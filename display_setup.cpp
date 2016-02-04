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
/// @file   display_setup.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Display Main Class
//=============================================================================
#include <Time.h>

#include "aquarium.h"

#include "display_main.h"

#include "display_setup.h"

DisplaySetup::DisplaySetup() {
  count = 0;
}

DisplaySetup::~DisplaySetup() {

}

void DisplaySetup::OnInit() {
  ClearScreen();
  SetCursor(0, 15);
  PrintLine(F("SETUP:"));
  PrintLine(F(""));
  PrintLine(F("X1:"));
  PrintLine(F(""));
  PrintLine(F("X2:"));
  PrintLine(F("XX.XX.XX"));
  PrintLine(F("X3:"));
}

void DisplaySetup::OnLoop() {
  //sensors.requestTemperaturesByIndex(0); // Temp abfragen

  // paint new temp
  // float temp = sensors.getTempCByIndex(0);
  float temp = 0;
  // tft.fillRect(20, 20, 90, 20, tft.color565(0xcc, 0xcc, 0xcc));
  SetCursor(20, 35); Print(temp); Print(F("\xB0")); Print(F("C"));

  // paint new time
  char buffer[32];
  snprintf(buffer, 30, "%.2d:%.2d:%.2d", hour(), minute(), second());
  // tft.fillRect(20, 60, 90, 20, tft.color565(0xcc, 0xcc, 0xcc));
  // SetCursor(20, 75); Print(buffer);

  snprintf(buffer, 30, "%.2d.%.2d.%.2d", day(), month(), year());
  // tft.fillRect(0, 100, 90, 20, tft.color565(0xcc, 0xcc, 0xcc));
  // SetCursor(0, 115); Print(buffer);

  count ++;

  if (count == 1000)
    aqua.setDisplay(new DisplayMain);
}
