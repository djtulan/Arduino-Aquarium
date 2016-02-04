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

#include "display_setup.h"

#include "display_main.h"

DisplayMain::DisplayMain() {
  tempconversion = false;
  mtime = 0;
}

DisplayMain::~DisplayMain() {

}

void DisplayMain::OnInit() {
  ClearScreen();
  SetCursor(0, 15);

  const uint16_t color = Color565(0xcc, 0xcc, 0xcc);
  FillRect(20, 20, 90, 20, color);
  FillRect(20, 60, 90, 20, color);
  FillRect(0, 100, 90, 20, color);

  DrawRect(19, 19, 92, 22, 0);
  DrawRect(19, 59, 92, 22, 0);
  DrawRect(0,  99, 91, 22, 0);

  PrintLine(F("Temperature:"));
  PrintLine(F(""));
  PrintLine(F("Time:"));
  PrintLine(F(""));
  PrintLine(F("Date:"));
  PrintLine(F("XX.XX.XX"));
  PrintLine(F("Free:"));
  PrintLine(F("Free:"));

  PaintIcon(0, 20, temp_icon_bits, temp_icon_width, temp_icon_height);
  PaintIcon(0, 60, clock_icon_bits, clock_icon_width, clock_icon_height);


}

void DisplayMain::OnLoop() {
  const uint16_t color = Color565(0xcc, 0xcc, 0xcc);

  if (tempconversion == false) {
    dallastemp.requestTemperaturesByIndex(0); // Temp abfragen
    mtime = millis();
  } else {
    if (millis() - mtime > 750) {
      tempconversion = false;
    }
  }

  // paint new temp
  float temp = dallastemp.getTempCByIndex(0);
  FillRect(20, 20, 90, 20, color);
  SetCursor(20, 35); Print(temp); Print(F("\xB0")); Print(F("C"));

  // paint new time
  char buffer[32];
  snprintf(buffer, 30, "%.2d:%.2d:%.2d", hour(), minute(), second());
  FillRect(20, 60, 90, 20, color);
  SetCursor(20, 75); Print(buffer);

  snprintf(buffer, 30, "%.2d.%.2d.%.2d", day(), month(), year());
  FillRect(0, 100, 90, 20, color);
  SetCursor(0, 115); Print(buffer);

  // paint
  //snprintf(buffer, 30, "%d", after - before);
  FillRect(0, 140, 90, 20, color);
  SetCursor(50, 155); Print(buffer);
}
