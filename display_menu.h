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
/// @file   display_menu.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Display Menu Class
//=============================================================================
#ifndef _DISPLAY_MENU_H_
#define _DISPLAY_MENU_H_

#include "display.h"

class DisplayMenu : public Display {
  public:
    DisplayMenu();
    ~DisplayMenu();

    virtual void OnInit();
    virtual void OnLoop();

  private:
    uint8_t focus;
};

#endif
