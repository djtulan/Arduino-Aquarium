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
/// @file   icons.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  icons
//=============================================================================
#include <Arduino.h>

#define clock_icon_width 20
#define clock_icon_height 20
extern const uint8_t clock_icon_bits[] PROGMEM;

#define heater_icon_width 20
#define heater_icon_height 20
extern const uint8_t heater_icon_bits[] PROGMEM;

#define light_icon_width 20
#define light_icon_height 20
extern const uint8_t light_icon_bits[] PROGMEM;

#define ph_icon_width 20
#define ph_icon_height 20
extern const uint8_t ph_icon_bits[] PROGMEM;

#define temp_icon_width 20
#define temp_icon_height 20
extern const uint8_t temp_icon_bits[] PROGMEM;
