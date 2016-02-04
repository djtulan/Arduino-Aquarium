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

// includes for time
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t


#include "display_main.h"
#include "aquarium.h"

// ===================================================
// TEMP SENSOR
// ===================================================
#define ONE_WIRE_BUS 2 /* Digitalport Pin 2 definieren */
OneWire ourWire(ONE_WIRE_BUS); /* Ini oneWire instance */
DallasTemperature dallastemp(&ourWire);/* Dallas Temperature Library für Nutzung der oneWire Library vorbereiten */
// ===================================================

Aquarium aqua;

/**
 * @brief arduino setup function
 */
void setup() {
  Display::Init();

  setSyncProvider(RTC.get); // the function to get the time from the RTC
  setTime(1453242148);

  dallastemp.begin(); // Inizialisieren der Dallas Temperature library
  dallastemp.setWaitForConversion(false);

  aqua.begin();
}

/**
 * @brief arduino loop function
 */
void loop() {
  aqua.loop();
}

Aquarium::Aquarium() {
  display = NULL;
}

Aquarium::~Aquarium() {
  delete (display);
}

void Aquarium::begin() {
  setDisplay(new DisplayMain); // start with main display
}

void Aquarium::loop() {
  if (display)
    display->OnLoop();
}

void Aquarium::setDisplay(Display *dsp) {
  delete (display);
  display = dsp;

  display->OnInit();
}
