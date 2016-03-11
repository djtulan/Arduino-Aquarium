//=============================================================================
// *** Arduino Aquarium ***
// Copyright (c) Robert Grasböck, All rights reserved.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3.0 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library.
//=============================================================================
/// @file   aquarium.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Main
//=============================================================================

#include <EEPROM.h>


// includes for time
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

// includes for temp
#include <OneWire.h>
#include <DallasTemperature.h>

// RF sender
#define RCSwitchDisableReceiving
#include <RCSwitch.h>

// Encoder
#include <Encoder.h>

#include "display_main.h"
#include "aquarium.h"

// ===================================================
// TEMP SENSOR
// ===================================================
#define ONE_WIRE_BUS 2 /* Digitalport Pin 2 definieren */
OneWire ourWire(ONE_WIRE_BUS); /* Ini oneWire instance */
DallasTemperature dallastemp(&ourWire);/* Dallas Temperature Library für Nutzung der oneWire Library vorbereiten */
// ===================================================

#define BUTTON_PIN_1  3
#define BUTTON_PIN_2  4
// #define BUTTON_PIN_3  5
// #define BUTTON_PIN_4  6

Encoder myEnc(5, 6);

RCSwitch mySwitch = RCSwitch();

Aquarium aqua;


/**
 * @brief arduino setup function
 */
void setup() {
  Serial.begin(9600);

  Display::Init();

  setSyncProvider(RTC.get); // the function to get the time from the RTC
  // RTC.set(1453240148);

  //setTime();

  // Transmitter is connected to Arduino Pin #10
  mySwitch.enableTransmit(7);

  dallastemp.begin(); // Inizialisieren der Dallas Temperature library
  dallastemp.setWaitForConversion(false);

  aqua.begin();

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
//  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
//  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
}

/**
 * @brief arduino loop function
 */
void loop() {
  aqua.loop();
}

Aquarium::Aquarium() {
  display = NULL;
  heater = 0;
  light = 0;
  temp = 0.0;

  counter = 0;

  myEnc.write(100);
}

Aquarium::~Aquarium() {
  delete(display);
}

void Aquarium::begin() {
  setDisplay(new DisplayMain); // start with main display

  LoadSetup();
}

void Aquarium::loop() {
  SerialDebug();

  if (display)
    display->OnLoop();

  // Heater Routine
  CheckTemp();

  // Light Routine
  CheckTime();

  int32_t val = myEnc.read();
  if (val != encval) {
    Serial.println(val - encval);
    encval = val;
  }

  // testcode
/*
  switch (counter) {
    case 0:
      mySwitch.switchOn("10101", "10000");
      break;

    case 1:
      mySwitch.switchOn("10101", "01000");
      break;

    case 2:
      mySwitch.switchOn("10101", "00100");
      break;

    case 3:
      mySwitch.switchOff("10101", "10000");
      break;

    case 4:
      mySwitch.switchOff("10101", "01000");
      break;

    case 5:
      mySwitch.switchOff("10101", "00100");
      break;
  }

  counter ++;

  if (counter == 6)
    counter = 0;
  */
}

void Aquarium::setDisplay(Display *dsp) {
  delete(display); // delete old display
  display = dsp;

  display->OnInit();
}

void Aquarium::RequestTemp() {
  dallastemp.requestTemperaturesByIndex(0); // Temp abfragen mnjh
}

float Aquarium::GetTempValue() {
  temp = dallastemp.getTempCByIndex(0);
  return temp;
}

float Aquarium::GetpHValue() {
  return 7.10;
}

uint8_t Aquarium::GetLightState() {
  return light;
}

uint8_t Aquarium::GetHeaterState() {
  return heater;
}

uint8_t Aquarium::GetButtons() {
  uint8_t buttonstate = 0;

  if (digitalRead(BUTTON_PIN_1) == LOW) {
    buttonstate |= BUTTON_EXIT;
  }

  if (digitalRead(BUTTON_PIN_2) == LOW) {
    buttonstate |= BUTTON_DEC;
  }

  /*
  if (digitalRead(BUTTON_PIN_3) == LOW) {
    buttonstate |= BUTTON_INC;
  }

  if (digitalRead(BUTTON_PIN_4) == LOW) {
    buttonstate |= BUTTON_SET;
  }*/

  return buttonstate;
}

void Aquarium::CheckTemp() {

  if (heater == 1 && temp > 25.00) {

    OnHeaterOff();

  } else if (heater == 0 && temp < 24.00) {

    OnHeaterOn();

  }
}

void Aquarium::CheckTime() {
  int h = hour();

  if (light == 1 && (h >= 22 || h < 9)) {

    OnLightOff();

  } else if (light == 0 && (h >= 9 && h < 22)) {

    OnLightOn();

  }
}

void Aquarium::OnHeaterOn() {
  heater = 1;
}

void Aquarium::OnHeaterOff() {
  heater = 0;
}

void Aquarium::OnLightOn() {
  light = 1;
}

void Aquarium::OnLightOff() {
  light = 0;
}

void Aquarium::LoadSetup() {
  // read in all bytes from EEPROM
  for (int i = 0; i < sizeof(SETUP); i++) {
    uint8_t byte = EEPROM.read(i);
    ((uint8_t *)(&setup))[i] = byte;
  }

  // calculate checksum
  uint8_t cs = 0;

  for (int i = 0; i < sizeof(SETUP) - 1; i++) {
    cs |= ((uint8_t *)(&setup))[i];
  }

  // if checksum or magic bytes are not ok, then reset to default values
  if (cs != setup.chksum || setup.magic1 != 0x12 || setup.magic2 != 0x34) {
    setup.magic1 = 0x12;
    setup.hour_on = 9;
    setup.min_on = 0;
    setup.hour_off = 22;
    setup.min_off = 0;
    setup.temp_high = 24;
    setup.temp_low = 21;
    setup.magic2 = 0x34;
    setup.chksum = 0;

    SaveSetup(); // save to EEPROM
  }
}

void Aquarium::SaveSetup() {
  uint8_t cs = 0;

  for (int i = 0; i < sizeof(SETUP) - 1; i++) {
    // read stored byte
    uint8_t byte = EEPROM.read(i);

    // if byte is different, then overwrite it
    if (((uint8_t *)(&setup))[i] != byte) {
      EEPROM.write(i, ((uint8_t *)(&setup))[i]);
    }

    cs |= ((uint8_t *)(&setup))[i];
  }

  uint8_t csbyte = EEPROM.read(sizeof(SETUP) - 1);

  if (csbyte != cs)
    EEPROM.write(sizeof(SETUP) - 1, cs);
}

void Aquarium::SerialDebug() {

  if (Serial.available()) {
    Serial.read();

    Serial.println("===================");
    Serial.print("Temp            = ");
    Serial.println(GetTempValue());
    Serial.print("PH              = ");
    Serial.println(GetpHValue());
    Serial.print("Light           = ");
    Serial.println(GetLightState());
    Serial.print("Heater          = ");
    Serial.println(GetHeaterState());
    Serial.print("Encoder         = ");
    Serial.println(encval);
    Serial.print("Setup.magic1    = ");
    Serial.println(setup.magic1);
    Serial.print("Setup.hour_on   = ");
    Serial.println(setup.hour_on);
    Serial.print("Setup.min_on    = ");
    Serial.println(setup.min_on);
    Serial.print("Setup.hour_off  = ");
    Serial.println(setup.hour_off);
    Serial.print("Setup.min_off   = ");
    Serial.println(setup.min_off);
    Serial.print("Setup.temp_high = ");
    Serial.println(setup.temp_high);
    Serial.print("Setup.temp_low  = ");
    Serial.println(setup.temp_low);
    Serial.print("Setup.magic2    = ");
    Serial.println(setup.magic2);
    Serial.print("Setup.chksum    = ");
    Serial.println(setup.chksum);
    Serial.println("===================");
  }
}
