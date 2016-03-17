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
/// @file   display.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   January, 2016
/// @brief  Display Class
//=============================================================================

// includes for display
#include <SPI.h>

#include <PDQ_GFX.h>            // Core graphics library
#include "PDQ_ST7735_config.h"  // PIN Config
#include <PDQ_ST7735.h>         // Hardware-specific library

#include <Fonts/Ubuntu-L9pt7b.h>

#include "display.h"

// ===================================================
// DISPLAY
// ===================================================
PDQ_ST7735 tft; // PDQ: create LCD object
// ===================================================

const uint16_t Display::TEXT_COLOR = Display::Color565(0x00, 0x00, 0x00);
const uint16_t Display::ON_COLOR   = Display::Color565(0x00, 0xaa, 0x00);
const uint16_t Display::OFF_COLOR  = Display::Color565(0xaa, 0x00, 0x00);
const uint16_t Display::BG_COLOR   = Display::Color565(0xd6, 0xd9, 0xdf);
const uint16_t Display::ICON_COLOR = Display::Color565(0x4f, 0x4f, 0x4f);

void Display::Init() {
  tft.begin(); // initialize LCD

  tft.setFont(&Ubuntu_L9pt8b);
  tft.setTextWrap(false); // Allow text to run off right edge
  tft.setTextColor(tft.color565(0x00, 0x00, 0x00));

  tft.fillScreen(ST7735_RED);
  tft.setRotation(2);
}

Display::Display() {
}

Display::~Display() {
}

void Display::ClearScreen(uint16_t color) {
  tft.fillScreen(color);
}

void Display::FillRect(int x, int y, int w, int h, uint16_t color) {
  tft.fillRect(x, y, w, h, color);
}

void Display::DrawRect(int x, int y, int w, int h, uint16_t color) {
  tft.drawRect(x, y, w, h, color);
}

uint16_t Display::Color565(uint8_t r, uint8_t g, uint8_t b) {
  return (tft.color565(r, g, b));
}

size_t Display::PrintLine(const __FlashStringHelper *txt) {
  return tft.println(txt);
}

void Display::SetCursor(int x, int y) {
  tft.setCursor(x, y);
}

void Display::SetTextColor(uint16_t color) {
  tft.setTextColor(color);
}

size_t Display::Print(float val) {
  return tft.print(val);
}

size_t  Display::Print(const __FlashStringHelper *txt) {
  return tft.print(txt);
}

size_t Display::Print(const char *txt) {
  return tft.print(txt);
}

void Display::PaintDisplay(int16_t x, int16_t y, int16_t w, int16_t h) {
  tft.fillRect(x, y, w, h, ST7735_WHITE);
  tft.drawRect(x-1, y-1, w+2, h+2, tft.color565(0xc0, 0xc0, 0xc1));
  tft.drawFastHLine(x-1, y-1, w+2, tft.color565(0x8d, 0x8e, 0x8f));

  tft.drawFastHLine(x, y, w, tft.color565(0xcb, 0xcb, 0xcb));
  tft.drawFastHLine(x+1, y+1, w, tft.color565(0xe5, 0xe5, 0xe6));
}

void Display::ClearDisplay(int16_t x, int16_t y, int16_t w, int16_t h) {
  tft.fillRect(x, y+2, w, h-2, ST7735_WHITE);
}

/*
 f o*r (int i = 0; i < 0x10; i++) {
 tft.setAddrWindow(0, 0, 128-1, 160-1);

 uint16_t cnt = 0;
 uint16_t color = tft.color565((i << 4) | i, (i << 4) | i, (i << 4) | i);
 uint16_t curcolor = 0;

 const uint8_t *cmp = &schneemann[0];

 while (cmp < &schneemann[sizeof(schneemann)]) {
   cnt = pgm_read_byte(cmp++);
   if (cnt & 0x80)
     cnt = ((cnt & 0x7f) << 8) | pgm_read_byte(cmp++);

   #if defined(_PDQ_ST7735H_)
   tft.pushColor(curcolor, cnt); // PDQ_GFX has count
   #else
   while (cnt--)
     tft.pushColor(curcolor);  // Adafruit needs a loop
     #endif
     curcolor ^= color;
   }
   }
   */

void Display::PaintIcon(int16_t x, int16_t y, const uint8_t *bitmap,
                        int16_t w, int16_t h, uint16_t color) {
  tft.drawXBitmap(x, y, bitmap, w, h, color);
}
