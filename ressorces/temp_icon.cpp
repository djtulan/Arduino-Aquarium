
// File: "temp_icon.bmp": 20 x 20 (24 bpp, pixel offset 54, bytes per line 60, bitmap size 1200).
// BMP #0 "temp_icon" (20 x 20 with '.'=trans, ' '=black, 'X'=XOR, 'W'=white):

// *+-------+-------+---*
// +********************+
// |********....********|
// |*******.****.*******|
// |*******.*....*******|
// |*******.****.*******|
// |*******.*....*******|
// |*******.****.*******|
// |*******.*....*******|
// +*******.****.*******+
// |*******.*....*******|
// |*******.****.*******|
// |*******.****.*******|
// |******..****..******|
// |*****.********.*****|
// |*****.********.*****|
// |*****.********.*****|
// +*****..******..*****+
// |******.******.******|
// |******...**...******|
// |********....********|
// *+-------+-------+---*

// Compressed RLE data
const uint8_t temp_icon[] PROGMEM =
{
	0x00, 0x1c, 0x04, 0x0f, 0x01, 0x04, 0x01, 0x0e, 0x01, 0x01, 0x04, 0x0e, 0x01, 0x04, 0x01, 0x0e, 
	0x01, 0x01, 0x04, 0x0e, 0x01, 0x04, 0x01, 0x0e, 0x01, 0x01, 0x04, 0x0e, 0x01, 0x04, 0x01, 0x0e, 
	0x01, 0x01, 0x04, 0x0e, 0x01, 0x04, 0x01, 0x0e, 0x01, 0x04, 0x01, 0x0d, 0x02, 0x04, 0x02, 0x0b, 
	0x01, 0x08, 0x01, 0x0a, 0x01, 0x08, 0x01, 0x0a, 0x01, 0x08, 0x01, 0x0a, 0x02, 0x06, 0x02, 0x0b, 
	0x01, 0x06, 0x01, 0x0c, 0x03, 0x02, 0x03, 0x0e, 0x04, 0x08, 
};

// Compressed RLE size 74

// Test decompress:
// 11111111111111111111
// 11111111000011111111
// 11111110111101111111
// 11111110100001111111
// 11111110111101111111
// 11111110100001111111
// 11111110111101111111
// 11111110100001111111
// 11111110111101111111
// 11111110100001111111
// 11111110111101111111
// 11111110111101111111
// 11111100111100111111
// 11111011111111011111
// 11111011111111011111
// 11111011111111011111
// 11111001111110011111
// 11111101111110111111
// 11111100011000111111
// 11111111000011111111
// 

// EOF
