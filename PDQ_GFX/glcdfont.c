#ifndef FONT5X7_H
#define FONT5X7_H

#ifdef __AVR__
#include <avr/io.h>
#include <avr/pgmspace.h>
#else
#define PROGMEM
#endif

// Modified version of Standard ASCII 5x7 font
// NEATO ASCII 5x7 font
// BY: IxD SMART Design, ported by: aisencc

const unsigned char font[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00,   //0 null
  0x3E, 0x5B, 0x4F, 0x5B, 0x3E, //1
  0x3E, 0x6B, 0x4F, 0x6B, 0x3E, //2
  0x1C, 0x3E, 0x7C, 0x3E, 0x1C, //3
  0x18, 0x3C, 0x7E, 0x3C, 0x18, //4
  0x1C, 0x57, 0x7D, 0x57, 0x1C, //5
  0x1C, 0x5E, 0x7F, 0x5E, 0x1C, //6
  0x00, 0x18, 0x3C, 0x18, 0x00, //7
  0xFF, 0xE7, 0xC3, 0xE7, 0xFF, //8
  0x00, 0x18, 0x24, 0x18, 0x00, //9
  0xFF, 0xE7, 0xDB, 0xE7, 0xFF, //10
  0x30, 0x48, 0x3A, 0x06, 0x0E, //11
  0x26, 0x29, 0x79, 0x29, 0x26, //12
  0x40, 0x7F, 0x05, 0x05, 0x07, //13
  0x40, 0x7F, 0x05, 0x25, 0x3F, //14
  0x5A, 0x3C, 0xE7, 0x3C, 0x5A, //15
  0x7F, 0x3E, 0x1C, 0x1C, 0x08, //16
  0x08, 0x1C, 0x1C, 0x3E, 0x7F, //17
  0x14, 0x22, 0x7F, 0x22, 0x14, //18
  0x5F, 0x5F, 0x00, 0x5F, 0x5F, //19
  0x06, 0x09, 0x7F, 0x01, 0x7F, //20
  0x00, 0x66, 0x89, 0x95, 0x6A, //21
  0x60, 0x60, 0x60, 0x60, 0x60, //22
  0x94, 0xA2, 0xFF, 0xA2, 0x94, //23
  0x08, 0x04, 0x7E, 0x04, 0x08, //24
  0x10, 0x20, 0x7E, 0x20, 0x10, //25
  0x08, 0x08, 0x2A, 0x1C, 0x08, //26
  0x08, 0x1C, 0x2A, 0x08, 0x08, //27
  0x1E, 0x10, 0x10, 0x10, 0x10, //28
  0x0C, 0x1E, 0x0C, 0x1E, 0x0C, //29
  0x30, 0x38, 0x3E, 0x38, 0x30, //30
  0x06, 0x0E, 0x3E, 0x0E, 0x06, //31
  0x00, 0x00, 0x00, 0x00, 0x00, //32 (space)
  0x00, 0x00, 0x5F, 0x00, 0x00, //33 !
  0x00, 0x07, 0x00, 0x07, 0x00, //34 "
  0x14, 0x7F, 0x14, 0x7F, 0x14, //35 #
  0x24, 0x2A, 0x7F, 0x2A, 0x12, //36 $
  0x23, 0x13, 0x08, 0x64, 0x62, //37 %
  0x36, 0x49, 0x56, 0x20, 0x50, //38 &
  0x00, 0x08, 0x07, 0x03, 0x00, //39 ‘
  0x00, 0x1C, 0x22, 0x41, 0x00, //40 (
    0x00, 0x41, 0x22, 0x1C, 0x00, //41 )
    0x2A, 0x1C, 0x7F, 0x1C, 0x2A, //42 *
    0x08, 0x08, 0x3E, 0x08, 0x08, //43 +
    0x00, 0x80, 0x70, 0x30, 0x00, //44 ,
    0x08, 0x08, 0x08, 0x08, 0x08, //45 -
    0x00, 0x00, 0x60, 0x60, 0x00, //46 .
    0x20, 0x10, 0x08, 0x04, 0x02, //47 /
    0x3E, 0x51, 0x49, 0x45, 0x3E, //48 0
    0x00, 0x42, 0x7F, 0x40, 0x00, //49 1
    0x72, 0x49, 0x49, 0x49, 0x46, //50 2
    0x21, 0x41, 0x49, 0x4D, 0x33, //51 3
    0x18, 0x14, 0x12, 0x7F, 0x10, //52 4
    0x27, 0x45, 0x45, 0x45, 0x39, //53 5
    0x3C, 0x4A, 0x49, 0x49, 0x31, //54 6
    0x41, 0x21, 0x11, 0x09, 0x07, //55 7
    0x36, 0x49, 0x49, 0x49, 0x36, //56 8
    0x46, 0x49, 0x49, 0x29, 0x1E, //57 9
    0x00, 0x00, 0x14, 0x00, 0x00, //58 :
    0x00, 0x40, 0x34, 0x00, 0x00, //59 ;
    0x00, 0x08, 0x14, 0x22, 0x41, //60 <
    0x14, 0x14, 0x14, 0x14, 0x14, //61 =
    0x00, 0x41, 0x22, 0x14, 0x08, //62 >
    0x02, 0x01, 0x59, 0x09, 0x06, //63 ?
    0x3E, 0x41, 0x5D, 0x59, 0x4E, //64 @
    0x7E, 0x09, 0x09, 0x09, 0x7E, //65 A
    0x7F, 0x49, 0x49, 0x49, 0x36, //66 B
    0x3E, 0x41, 0x41, 0x41, 0x00, //67 C
    0x7F, 0x41, 0x41, 0x22, 0x1C, //68 D
    0x7F, 0x49, 0x49, 0x49, 0x41, //69 E
    0x7F, 0x09, 0x09, 0x09, 0x01, //70 F
    0x3E, 0x41, 0x49, 0x49, 0x38, //71 G
    0x7F, 0x08, 0x08, 0x08, 0x7F, //72 H
    0x00, 0x00, 0x7F, 0x00, 0x00, //73 I
    0x20, 0x40, 0x40, 0x40, 0x3F, //74 J
    0x7F, 0x08, 0x14, 0x22, 0x41, //75 K
    0x7F, 0x40, 0x40, 0x40, 0x40, //76 L
    0x7F, 0x02, 0x04, 0x02, 0x7F, //77 M
    0x7F, 0x02, 0x04, 0x08, 0x7F, //78 N
    0x3E, 0x41, 0x41, 0x41, 0x3E, //79 O
    0x7F, 0x09, 0x09, 0x09, 0x06, //80 P
    0x3E, 0x41, 0x41, 0x61, 0x7E, //81 Q
    0x7F, 0x09, 0x19, 0x29, 0x46, //82 R
    0x26, 0x49, 0x49, 0x49, 0x32, //83 S
    0x01, 0x01, 0x7F, 0x01, 0x01, //84 T
    0x3F, 0x40, 0x40, 0x40, 0x3F, //85 U
    0x1F, 0x20, 0x40, 0x20, 0x1F, //86 V
    0x7F, 0x20, 0x10, 0x20, 0x7F, //87 W
    0x63, 0x14, 0x08, 0x14, 0x63, //88 X
    0x07, 0x08, 0x78, 0x08, 0x07, //89 Y
    0x61, 0x51, 0x49, 0x45, 0x43, //90 Z
    0x00, 0x7F, 0x41, 0x41, 0x41, //91
    0x02, 0x04, 0x08, 0x10, 0x20, //92
    0x00, 0x41, 0x41, 0x41, 0x7F, //93
    0x04, 0x02, 0x01, 0x02, 0x04, //94
    0x40, 0x40, 0x40, 0x40, 0x40, //95
    0x00, 0x03, 0x07, 0x08, 0x00, //96
    0x20, 0x54, 0x54, 0x78, 0x40, //97  a
    0x7F, 0x28, 0x44, 0x44, 0x38, //98  b
    0x38, 0x44, 0x44, 0x44, 0x28, //99  c
    0x38, 0x44, 0x44, 0x28, 0x7F, //100 d
    0x38, 0x54, 0x54, 0x54, 0x18, //101 e
    0x00, 0x08, 0x7E, 0x09, 0x02, //102 f
    0x18, 0xA4, 0xA4, 0x9C, 0x78, //103 g
    0x7F, 0x08, 0x04, 0x04, 0x78, //104 h
    0x00, 0x44, 0x7D, 0x40, 0x00, //105 i
    0x20, 0x40, 0x40, 0x3D, 0x00, //106 j
    0x7F, 0x10, 0x28, 0x44, 0x00, //107 k
    0x00, 0x41, 0x7F, 0x40, 0x00, //108 l
    0x7C, 0x04, 0x78, 0x04, 0x78, //109 m
    0x7C, 0x08, 0x04, 0x04, 0x78, //110 n
    0x38, 0x44, 0x44, 0x44, 0x38, //111 o
    0xFC, 0x18, 0x24, 0x24, 0x18, //112 p
    0x18, 0x24, 0x24, 0x18, 0xFC, //113 q
    0x7C, 0x08, 0x04, 0x04, 0x08, //114 r
    0x48, 0x54, 0x54, 0x54, 0x24, //115 s
    0x04, 0x04, 0x3F, 0x44, 0x24, //116 t
    0x3C, 0x40, 0x40, 0x20, 0x7C, //117 u
    0x1C, 0x20, 0x40, 0x20, 0x1C, //118 v
    0x3C, 0x40, 0x30, 0x40, 0x3C, //119 w
    0x44, 0x28, 0x10, 0x28, 0x44, //120 x
    0x4C, 0x90, 0x90, 0x90, 0x7C, //121 y
    0x44, 0x64, 0x54, 0x4C, 0x44, //122 z
    0x00, 0x08, 0x36, 0x41, 0x00, //123 {
    0x00, 0x00, 0x77, 0x00, 0x00, //124 |
    0x00, 0x41, 0x36, 0x08, 0x00, //125 }
    0x02, 0x01, 0x02, 0x04, 0x02, //126 ~
    0x3C, 0x26, 0x23, 0x26, 0x3C, //127 (delete)
    0x1E, 0xA1, 0xA1, 0x61, 0x12, //128 €
    0x3A, 0x40, 0x40, 0x20, 0x7A, //129
    0x38, 0x54, 0x54, 0x55, 0x59, //130 ‚
    0x21, 0x55, 0x55, 0x79, 0x41, //131 ƒ
    0x21, 0x54, 0x54, 0x78, 0x41, //132 „
    0x21, 0x55, 0x54, 0x78, 0x40, //133 …
    0x20, 0x54, 0x55, 0x79, 0x40, //134 †
    0x0C, 0x1E, 0x52, 0x72, 0x12, //135 ‡
    0x39, 0x55, 0x55, 0x55, 0x59, //136 ˆ
    0x39, 0x54, 0x54, 0x54, 0x59, //137 ‰
    0x39, 0x55, 0x54, 0x54, 0x58, //138 Š
    0x00, 0x00, 0x45, 0x7C, 0x41, //139 ‹
    0x00, 0x02, 0x45, 0x7D, 0x42, //140 Œ
    0x00, 0x01, 0x45, 0x7C, 0x40, //141
    0xF0, 0x29, 0x24, 0x29, 0xF0, //142 Ž
    0xF0, 0x28, 0x25, 0x28, 0xF0, //143
    0x7C, 0x54, 0x55, 0x45, 0x00, //144
    0x20, 0x54, 0x54, 0x7C, 0x54, //145 ‘
    0x7C, 0x0A, 0x09, 0x7F, 0x49, //146 ’
    0x32, 0x49, 0x49, 0x49, 0x32, //147 “
    0x32, 0x48, 0x48, 0x48, 0x32, //148 ”
    0x32, 0x4A, 0x48, 0x48, 0x30, //149 •
    0x3A, 0x41, 0x41, 0x21, 0x7A, //150 –
    0x3A, 0x42, 0x40, 0x20, 0x78, //151 —
    0x00, 0x9D, 0xA0, 0xA0, 0x7D, //152 ˜
    0x39, 0x44, 0x44, 0x44, 0x39, //153 ™
    0x3D, 0x40, 0x40, 0x40, 0x3D, //154 š
    0x3C, 0x24, 0xFF, 0x24, 0x24, //155 ›
    0x48, 0x7E, 0x49, 0x43, 0x66, //156 œ
    0x2B, 0x2F, 0xFC, 0x2F, 0x2B, //157
    0xFF, 0x09, 0x29, 0xF6, 0x20, //158 ž
    0xC0, 0x88, 0x7E, 0x09, 0x03, //159 Ÿ
    0x20, 0x54, 0x54, 0x79, 0x41, //160
    0x00, 0x00, 0x44, 0x7D, 0x41, //161 ¡
    0x30, 0x48, 0x48, 0x4A, 0x32, //162 ¢
    0x38, 0x40, 0x40, 0x22, 0x7A, //163 £
    0x00, 0x7A, 0x0A, 0x0A, 0x72, //164 ¤
    0x7D, 0x0D, 0x19, 0x31, 0x7D, //165 ¥
    0x26, 0x29, 0x29, 0x2F, 0x28, //166 ¦
    0x26, 0x29, 0x29, 0x29, 0x26, //167 §
    0x30, 0x48, 0x4D, 0x40, 0x20, //168 ¨
    0x38, 0x08, 0x08, 0x08, 0x08, //169 ©
    0x08, 0x08, 0x08, 0x08, 0x38, //170 ª
    0x2F, 0x10, 0xC8, 0xAC, 0xBA, //171 «
    0x2F, 0x10, 0x28, 0x34, 0xFA, //172 ¬
    0x00, 0x00, 0x7B, 0x00, 0x00, //173
    0x08, 0x14, 0x2A, 0x14, 0x22, //174 ®
    0x22, 0x14, 0x2A, 0x14, 0x08, //175 ¯
    0xAA, 0x00, 0x55, 0x00, 0xAA, //176 °
    0xAA, 0x55, 0xAA, 0x55, 0xAA, //177 ±
    0x00, 0x00, 0x00, 0xFF, 0x00, //178 ²
    0x10, 0x10, 0x10, 0xFF, 0x00, //179 ³
    0x14, 0x14, 0x14, 0xFF, 0x00, //180 ´
    0x10, 0x10, 0xFF, 0x00, 0xFF, //181 µ
    0x10, 0x10, 0xF0, 0x10, 0xF0, //182 ¶
    0x14, 0x14, 0x14, 0xFC, 0x00, //183 ·
    0x14, 0x14, 0xF7, 0x00, 0xFF, //184 ¸
    0x00, 0x00, 0xFF, 0x00, 0xFF, //185 ¹
    0x14, 0x14, 0xF4, 0x04, 0xFC, //186 º
    0x14, 0x14, 0x17, 0x10, 0x1F, //187 »
    0x10, 0x10, 0x1F, 0x10, 0x1F, //188 ¼
    0x14, 0x14, 0x14, 0x1F, 0x00, //189 ½
    0x10, 0x10, 0x10, 0xF0, 0x00, //190 ¾
    0x00, 0x00, 0x00, 0x1F, 0x10, //191 ¿
    0x10, 0x10, 0x10, 0x1F, 0x10, //192 À
    0x10, 0x10, 0x10, 0xF0, 0x10, //193 Á
    0x00, 0x00, 0x00, 0xFF, 0x10, //194 Â
    0x10, 0x10, 0x10, 0x10, 0x10, //195 Ã
    0x10, 0x10, 0x10, 0xFF, 0x10, //196 Ä
    0x00, 0x00, 0x00, 0xFF, 0x14, //197 Å
    0x00, 0x00, 0xFF, 0x00, 0xFF, //198 Æ
    0x00, 0x00, 0x1F, 0x10, 0x17, //199 Ç
    0x00, 0x00, 0xFC, 0x04, 0xF4, //200 È
    0x14, 0x14, 0x17, 0x10, 0x17, //201 É
    0x14, 0x14, 0xF4, 0x04, 0xF4, //202 Ê
    0x00, 0x00, 0xFF, 0x00, 0xF7, //203 Ë
    0x14, 0x14, 0x14, 0x14, 0x14, //204 Ì
    0x14, 0x14, 0xF7, 0x00, 0xF7, //205 Í
    0x14, 0x14, 0x14, 0x17, 0x14, //206 Î
    0x10, 0x10, 0x1F, 0x10, 0x1F, //207 Ï
    0x14, 0x14, 0x14, 0xF4, 0x14, //208 Ð
    0x10, 0x10, 0xF0, 0x10, 0xF0, //219 Ñ
    0x00, 0x00, 0x1F, 0x10, 0x1F, //210 Ò
    0x00, 0x00, 0x00, 0x1F, 0x14, //211 Ó
    0x00, 0x00, 0x00, 0xFC, 0x14, //212 Ô
    0x00, 0x00, 0xF0, 0x10, 0xF0, //213 Õ
    0x10, 0x10, 0xFF, 0x10, 0xFF, //214 Ö
    0x14, 0x14, 0x14, 0xFF, 0x14, //215 ×
    0x10, 0x10, 0x10, 0x1F, 0x00, //216 Ø
    0x00, 0x00, 0x00, 0xF0, 0x10, //217 Ù
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //218 Ú
    0xF0, 0xF0, 0xF0, 0xF0, 0xF0, //219 Û
    0xFF, 0xFF, 0xFF, 0x00, 0x00, //220 Ü
    0x00, 0x00, 0x00, 0xFF, 0xFF, //221 Ý
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, //222 Þ
    0x38, 0x44, 0x44, 0x38, 0x44, //223 ß
    0x7C, 0x2A, 0x2A, 0x3E, 0x14, //224 à
    0x7E, 0x02, 0x02, 0x06, 0x06, //225 á
    0x02, 0x7E, 0x02, 0x7E, 0x02, //226 â
    0x63, 0x55, 0x49, 0x41, 0x63, //227 ã
    0x38, 0x44, 0x44, 0x3C, 0x04, //228 ä
    0x40, 0x7E, 0x20, 0x1E, 0x20, //239 å
    0x06, 0x02, 0x7E, 0x02, 0x02, //230 æ
    0x99, 0xA5, 0xE7, 0xA5, 0x99, //231 ç
    0x1C, 0x2A, 0x49, 0x2A, 0x1C, //232 è
    0x4C, 0x72, 0x01, 0x72, 0x4C, //233 é
    0x30, 0x4A, 0x4D, 0x4D, 0x30, //234 ê
    0x30, 0x48, 0x78, 0x48, 0x30, //235 ë
    0xBC, 0x62, 0x5A, 0x46, 0x3D, //236 ì
    0x3E, 0x49, 0x49, 0x49, 0x00, //237 í
    0x7E, 0x01, 0x01, 0x01, 0x7E, //238 î
    0x2A, 0x2A, 0x2A, 0x2A, 0x2A, //239 ï
    0x44, 0x44, 0x5F, 0x44, 0x44, //240 ð
    0x40, 0x51, 0x4A, 0x44, 0x40, //241 ñ
    0x40, 0x44, 0x4A, 0x51, 0x40, //242 ò
    0x00, 0x00, 0xFF, 0x01, 0x03, //243 ó
    0xE0, 0x80, 0xFF, 0x00, 0x00, //244 ô
    0x08, 0x08, 0x6B, 0x6B, 0x08, //245 õ
    0x36, 0x12, 0x36, 0x24, 0x36, //246 ö
    0x06, 0x0F, 0x09, 0x0F, 0x06, //247 ÷
    0x00, 0x00, 0x18, 0x18, 0x00, //248 ø
    0x00, 0x00, 0x10, 0x10, 0x00, //249 ù
    0x30, 0x40, 0xFF, 0x01, 0x01, //250 ú
    0x00, 0x1F, 0x01, 0x01, 0x1E, //251 û
    0x00, 0x19, 0x1D, 0x17, 0x12, //252 ü
    0x00, 0x3C, 0x3C, 0x3C, 0x3C, //253 ý
    0x00, 0x00, 0x00, 0x00, 0x00  //254 þ

};
#endif // FONT5X7_H


