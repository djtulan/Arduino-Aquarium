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
/// @file   display_main.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Display Main Class
//=============================================================================
#include <Arduino.h>
#include <Time.h>

#include "aquarium.h"
#include "icons.h"

#include "display_menu.h"

#include "display_main.h"

#define DISPLAY1_X               30
#define DISPLAY1_Y               10
#define DISPLAY2_X       DISPLAY1_X
#define DISPLAY2_Y               40
#define DISPLAY3_X       DISPLAY1_X
#define DISPLAY3_Y               70
#define DISPLAY4_X       DISPLAY1_X
#define DISPLAY4_Y              100
#define DISPLAY5_X       DISPLAY1_X
#define DISPLAY5_Y              130
#define DISPLAY6_X  DISPLAY5_X + 64
#define DISPLAY6_Y       DISPLAY5_Y

#define DISPLAY_W                90
#define DISPLAY_H                20
#define DISPLAY_SMALL_W          26
#define DISPLAY_SMALL_H          20

#define ICON1_X                   4
#define ICON1_Y          DISPLAY1_Y
#define ICON2_X             ICON1_X
#define ICON2_Y          DISPLAY2_Y
#define ICON3_X             ICON1_X
#define ICON3_Y          DISPLAY3_Y
#define ICON4_X             ICON1_X
#define ICON4_Y          DISPLAY4_Y
#define ICON5_X             ICON1_X
#define ICON5_Y          DISPLAY5_Y
#define ICON6_X        ICON5_X + 64
#define ICON6_Y             ICON5_Y

DisplayMain::DisplayMain() {
  tempconversion = false;
  mtime = 0;

  old_temp = 0;
  old_sec = 0;
  old_day = 0;
  old_ph = 0;
  old_light = 0xff, old_heater = 0xff;
}

DisplayMain::~DisplayMain() {

}

void DisplayMain::OnInit() {
  ClearScreen(BG_COLOR);

  PaintDisplay(DISPLAY1_X, DISPLAY1_Y, DISPLAY_W, DISPLAY_H);
  PaintDisplay(DISPLAY2_X, DISPLAY2_Y, DISPLAY_W, DISPLAY_H);
  PaintDisplay(DISPLAY3_X, DISPLAY3_Y, DISPLAY_W, DISPLAY_H);
  PaintDisplay(DISPLAY4_X, DISPLAY4_Y, DISPLAY_W, DISPLAY_H);
  PaintDisplay(DISPLAY5_X, DISPLAY5_Y, DISPLAY_SMALL_W, DISPLAY_SMALL_H);
  PaintDisplay(DISPLAY6_X, DISPLAY6_Y, DISPLAY_SMALL_W, DISPLAY_SMALL_H);

  PaintIcon(ICON1_X,  ICON1_Y, temp_icon_bits,   temp_icon_width,   temp_icon_height,   ICON_COLOR);
  PaintIcon(ICON2_X,  ICON2_Y, clock_icon_bits,  clock_icon_width,  clock_icon_height,  ICON_COLOR);
  PaintIcon(ICON3_X,  ICON3_Y, heater_icon_bits, heater_icon_width, heater_icon_height, ICON_COLOR);
  PaintIcon(ICON4_X,  ICON4_Y, ph_icon_bits,     ph_icon_width,     ph_icon_height,     ICON_COLOR);
  PaintIcon(ICON5_X,  ICON5_Y, light_icon_bits,  light_icon_width,  light_icon_height,  ICON_COLOR);
  PaintIcon(ICON6_X,  ICON6_Y, heater_icon_bits, heater_icon_width, heater_icon_height, ICON_COLOR);
}

void DisplayMain::OnLoop() {
  SetTextColor(TEXT_COLOR);

  if (tempconversion == false) {
    aqua.RequestTemp();
    mtime = millis();
  } else {
    if (millis() - mtime > 750) {
      tempconversion = false;
    }
  }

  // ========================
  // paint new temp
  // ========================
  float temp = aqua.GetTempValue();

  if (temp != old_temp) {
    ClearDisplay(DISPLAY1_X, DISPLAY1_Y, DISPLAY_W, DISPLAY_H);
    SetCursor(DISPLAY1_X + 12, DISPLAY1_Y + 15);
    Print(temp);
    Print(F("\xB0"));
    Print(F("C"));

    old_temp = temp;
  }

  char buffer[32];

  // ========================
  // paint new time
  // ========================
  if (second() != old_sec) {
    snprintf(buffer, 30, "%.2d:%.2d:%.2d", hour(), minute(), second());
    ClearDisplay(DISPLAY2_X, DISPLAY2_Y, DISPLAY_W, DISPLAY_H);
    SetCursor(DISPLAY2_X + 10, DISPLAY2_Y + 15);
    Print(buffer);

    old_sec = second();
  }

  // ========================
  // paint new date
  // ========================
  if (day() != old_day) {
    snprintf(buffer, 30, "%.2d.%.2d.%.2d", day(), month(), year());
    ClearDisplay(DISPLAY3_X, DISPLAY3_Y, DISPLAY_W, DISPLAY_H);
    SetCursor(DISPLAY3_X, DISPLAY3_Y + 15);
    Print(buffer);

    old_day = day();
  }

  // ========================
  // paint new ph
  // ========================
  float ph = aqua.GetpHValue();

  if (ph != old_ph) {
    ClearDisplay(DISPLAY4_X, DISPLAY4_Y, DISPLAY_W, DISPLAY_H);
    SetCursor(DISPLAY4_X + 25, DISPLAY4_Y + 15);
    Print(ph);

    old_ph = ph;
  }

  // ========================
  // paint new light
  // ========================
  uint8_t light = aqua.GetLightState();

  if (light != old_light) {
    ClearDisplay(DISPLAY5_X, DISPLAY5_Y, DISPLAY_SMALL_W, DISPLAY_SMALL_H);
    SetCursor(DISPLAY5_X, DISPLAY5_Y + 15);

    if (light == 0) {
      SetTextColor(OFF_COLOR);
      Print(F("off"));
    } else {
      SetTextColor(ON_COLOR);
      Print(F("on"));
    }

    old_light = light;
  }

  // ========================
  // paint new heater
  // ========================
  uint8_t heater = aqua.GetHeaterState();

  if (heater != old_heater) {
    ClearDisplay(DISPLAY6_X, DISPLAY6_Y, DISPLAY_SMALL_W, DISPLAY_SMALL_H);
    SetCursor(DISPLAY6_X, DISPLAY6_Y + 15);

    if (heater == 0) {
      SetTextColor(OFF_COLOR);
      Print(F("off"));
    } else {
      SetTextColor(ON_COLOR);
      Print(F("on"));
    }

    old_heater = heater;
  }

  if (aqua.GetButtons()) {
    while (aqua.GetButtons())
      ;
    aqua.setDisplay(new DisplayMenu());
  }
}
