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
/// @file   display_menu.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Display Menu Class
//=============================================================================
#include <Time.h>

#include "aquarium.h"

#include "display_main.h"
#include "display_setup.h"
#include "display_maintenance.h"

#include "display_menu.h"

DisplayMenu::DisplayMenu() {
  focus = 0;
}

DisplayMenu::~DisplayMenu() {
}

void DisplayMenu::OnInit() {
  focus = 0;

  ClearScreen(BG_COLOR);

  SetCursor(0, 15);
  PrintLine(F("MENU:"));
  PrintLine(F(""));
  PrintLine(F("SETUP"));
  PrintLine(F("MAINTANACE"));
}

void DisplayMenu::OnLoop() {
  uint8_t btns = aqua.GetButtons();

  switch (btns) {
    case Aquarium::BUTTON_EXIT:
      while (aqua.GetButtons())
        ;
      aqua.setDisplay(new DisplayMain());
      break;

    case Aquarium::BUTTON_DEC:
      if (focus == 0)
        focus = 1;
      else
        focus --;
      break;

    case Aquarium::BUTTON_INC:
      if (focus == 1)
        focus = 0;
      else
        focus ++;
      break;

    case Aquarium::BUTTON_SET:
      switch (focus) {
        case 0:
          aqua.setDisplay(new DisplaySetup());
          break;

        case 1:
          // aqua.setDisplay(new DisplayMaintenance());
          break;
      }
      break;
  }
}
