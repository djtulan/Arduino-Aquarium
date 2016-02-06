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
/// @file   display.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Display Class
//=============================================================================
#include <Arduino.h>

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

class Display {
  public:
    Display();
    virtual ~Display();

    static void Init();

    virtual void OnInit() = 0;
    virtual void OnLoop() = 0;

    void ClearScreen(uint16_t color);

    void FillRect(int x, int y, int w, int h, uint16_t color);
    void DrawRect(int x, int y, int w, int h, uint16_t color);

    static uint16_t Color565(uint8_t r, uint8_t g, uint8_t b);

    void SetCursor(int x, int y);
    void SetTextColor(uint16_t color);

    size_t PrintLine(const __FlashStringHelper *txt);
    size_t Print(float val);
    size_t Print(const __FlashStringHelper *txt);
    size_t Print(const char *txt);

    void PaintIcon(int16_t x, int16_t y, const uint8_t *bitmap,
                   int16_t w, int16_t h, uint16_t color);

    void PaintDisplay(int16_t x, int16_t y, int16_t w, int16_t h);
    void ClearDisplay(int16_t x, int16_t y, int16_t w, int16_t h);

    static const uint16_t TEXT_COLOR;
    static const uint16_t ON_COLOR;
    static const uint16_t OFF_COLOR;
    static const uint16_t BG_COLOR;
    static const uint16_t ICON_COLOR;
};

#endif
