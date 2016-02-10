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


    /**
     * @brief set current display object
     * @param [in] display object
     *
     * A Display object is a object of the base class Display
     * It's one screen representation
     */
    void setDisplay(Display *dsp);


    /**
     * @brief Request temperature from Dallas sensor
     */
    void RequestTemp();

    /**
     * @brief Get Temp of Dallas sensor after requesting it
     * @return current temperature value
     */
    float GetTempValue();

    /**
     * @brief Get pH value from sensor
     * @return current pH value (0 ... 14)
     */
    float GetpHValue();

    /**
     * @brief Get light state
     * @return current light state (0/1)
     */
    uint8_t GetLightState();

    /**
     * @brief Get heater state
     * @return current heater state (0/1)
     */
    uint8_t GetHeaterState();


    /// \brief button masks
    enum ButtonMasks {
      BUTTON_EXIT = 1, ///< button exit pressed mask
      BUTTON_DEC = 2,  ///< button decrement pressed mask
      BUTTON_INC = 4,  ///< button increment pressed mask
      BUTTON_SET = 8,  ///< button set pressed mask
    };

    /**
     * @brief Get button state
     * @return or'd button masks
     */
    uint8_t GetButtons();

    

  private:
    void CheckTemp();
    void CheckTime();

    void OnHeaterOn();
    void OnHeaterOff();

    void OnLightOn();
    void OnLightOff();

    void LoadSetup();
    void SaveSetup();

    void SerialDebug();

    Display *display;
    uint8_t heater;
    uint8_t light;
    float temp;

    /// \brief setup stored on the EEPROM
    struct SETUP {
      uint8_t magic1;
      uint8_t hour_on;
      uint8_t min_on;
      uint8_t hour_off;
      uint8_t min_off;
      uint8_t temp_high;
      uint8_t temp_low;
      uint8_t magic2;
      uint8_t chksum;
    };
    SETUP setup;
};

/// aquarium object
extern Aquarium aqua;

#endif
