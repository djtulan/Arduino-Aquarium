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
/// @file   aquarium.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Main
//=============================================================================
#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

// includes for temp
#include <OneWire.h>
#include <DallasTemperature.h>

#include "display.h"

class Aquarium {
  public:
    /**
     * @brief constructor of Aquarium
     */
    Aquarium();

    /**
     * @brief destructor of Aquarium
     */
    ~Aquarium();

    /**
     * @brief begin with first state
     */
    void begin();

    /**
     * @brief loop method
     */
    void loop();

    void setDisplay(Display *dsp);

  private:
    Display *display;
};

/// aquarium object
extern Aquarium aqua;
/// temperature sensor object
extern DallasTemperature dallastemp;

#endif
