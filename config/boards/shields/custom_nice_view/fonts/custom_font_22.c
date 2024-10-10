/*******************************************************************************
 * Size: 22 px
 * Bpp: 1
 * Opts: --bpp 1 --size 22 --no-compress --font LoRes22OTSerif-Bold.woff --range 32-127 --format lvgl -o custom_font_22.c
 ******************************************************************************/

#include "./custom_font_22.h"

#ifndef CUSTOM_FONT_22
#define CUSTOM_FONT_22 1
#endif

#if CUSTOM_FONT_22

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xff, 0x3c,

    /* U+0022 "\"" */
    0xb6, 0xd0,

    /* U+0023 "#" */
    0x52, 0xbe, 0xa5, 0x2b, 0xea, 0x50,

    /* U+0024 "$" */
    0x21, 0x8, 0x7, 0xe7, 0x1c, 0x71, 0xc6, 0x39,
    0xf8, 0x4, 0x21, 0x0,

    /* U+0025 "%" */
    0x7f, 0x86, 0xc4, 0x36, 0x21, 0xb2, 0xd, 0x90,
    0x6c, 0x81, 0xc8, 0x0, 0x40, 0x2, 0x70, 0x26,
    0xc1, 0x36, 0x9, 0xb0, 0x8d, 0x84, 0x6c, 0x21,
    0xc0,

    /* U+0026 "&" */
    0x7b, 0x2c, 0x30, 0xc3, 0x7, 0x30, 0xc3, 0x3c,
    0xb2, 0xcb, 0x27, 0x40,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x2b, 0x6d, 0xb6, 0xdb, 0x6d, 0xb6, 0xc8, 0x80,

    /* U+0029 ")" */
    0x89, 0xb6, 0xdb, 0x6d, 0xb6, 0xdb, 0x6a, 0x0,

    /* U+002A "*" */
    0x25, 0x5d, 0x52, 0x0,

    /* U+002B "+" */
    0x21, 0x9, 0xf2, 0x10, 0x80,

    /* U+002C "," */
    0xf6,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0x42, 0x21, 0x8, 0x84, 0x22, 0x10, 0x88,
    0x42, 0x0,

    /* U+0030 "0" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xcf, 0x37, 0x80,

    /* U+0031 "1" */
    0x6e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf0,

    /* U+0032 "2" */
    0xf4, 0xc6, 0x31, 0x8c, 0xc6, 0x63, 0x31, 0x8c,
    0x67, 0xe0,

    /* U+0033 "3" */
    0xf4, 0xc6, 0x31, 0x8c, 0x6e, 0x18, 0xc6, 0x31,
    0x8f, 0xc0,

    /* U+0034 "4" */
    0x18, 0x61, 0x86, 0x59, 0x65, 0xa6, 0x9a, 0x6f,
    0xc6, 0x18, 0x61, 0x80,

    /* U+0035 "5" */
    0xfe, 0x71, 0x8c, 0x63, 0xc3, 0x18, 0xc6, 0x31,
    0x8f, 0xc0,

    /* U+0036 "6" */
    0x18, 0xc6, 0x18, 0xc3, 0xf, 0xb3, 0xcf, 0x3c,
    0xf3, 0xcf, 0x37, 0x80,

    /* U+0037 "7" */
    0xfe, 0x30, 0xc3, 0xc, 0x61, 0x8c, 0x31, 0x86,
    0x18, 0x61, 0x86, 0x0,

    /* U+0038 "8" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x37, 0xb3, 0xcf, 0x3c,
    0xf3, 0xcf, 0x37, 0x80,

    /* U+0039 "9" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x7c, 0x30,
    0xc6, 0x18, 0xc6, 0x0,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0xf0, 0xf, 0x60,

    /* U+003C "<" */
    0x11, 0x22, 0x44, 0x84, 0x42, 0x21, 0x10,

    /* U+003D "=" */
    0xf0, 0xf0,

    /* U+003E ">" */
    0x88, 0x44, 0x22, 0x12, 0x24, 0x48, 0x80,

    /* U+003F "?" */
    0xf4, 0xe6, 0x31, 0x8c, 0x66, 0x62, 0x10, 0x80,
    0x31, 0x80,

    /* U+0040 "@" */
    0x3c, 0x86, 0x6d, 0x5a, 0xb5, 0x6a, 0xd5, 0x9c,
    0x80, 0xf0,

    /* U+0041 "A" */
    0x18, 0x18, 0x18, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c,
    0x46, 0x46, 0x7e, 0x46, 0x46, 0x46, 0xef,

    /* U+0042 "B" */
    0xfc, 0xcd, 0x9b, 0x36, 0x6c, 0x9f, 0x33, 0x66,
    0xcd, 0x9b, 0x36, 0x6c, 0xbe, 0x0,

    /* U+0043 "C" */
    0x7e, 0x71, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x65, 0xc0,

    /* U+0044 "D" */
    0xfc, 0xcd, 0x9b, 0x36, 0x6c, 0xd9, 0xb3, 0x66,
    0xcd, 0x9b, 0x36, 0x6c, 0xbe, 0x0,

    /* U+0045 "E" */
    0xfd, 0x96, 0x18, 0x61, 0xa7, 0x9a, 0x61, 0x86,
    0x18, 0x61, 0x9f, 0xc0,

    /* U+0046 "F" */
    0xfd, 0x96, 0x18, 0x61, 0xa7, 0x9a, 0x61, 0x86,
    0x18, 0x61, 0x8f, 0x0,

    /* U+0047 "G" */
    0x7f, 0x1c, 0x30, 0xc3, 0xd, 0xf3, 0xcf, 0x3c,
    0xf3, 0xcf, 0x56, 0x40,

    /* U+0048 "H" */
    0xf7, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf7,

    /* U+0049 "I" */
    0xf6, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf0,

    /* U+004A "J" */
    0x79, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63,
    0x1b, 0x80,

    /* U+004B "K" */
    0xf7, 0x62, 0x62, 0x64, 0x64, 0x64, 0x78, 0x78,
    0x78, 0x6c, 0x6c, 0x6c, 0x66, 0x66, 0xf7,

    /* U+004C "L" */
    0xf1, 0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86,
    0x18, 0x61, 0x9f, 0xc0,

    /* U+004D "M" */
    0xe0, 0xec, 0x19, 0x83, 0x38, 0xe7, 0x1c, 0xe3,
    0x96, 0xb2, 0xd6, 0x5e, 0xc9, 0x99, 0x33, 0x26,
    0x64, 0xc, 0x81, 0xb8, 0x78,

    /* U+004E "N" */
    0xe7, 0x62, 0x62, 0x72, 0x72, 0x72, 0x5a, 0x5a,
    0x5a, 0x4e, 0x4e, 0x4e, 0x46, 0x46, 0xe6,

    /* U+004F "O" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xcf, 0x37, 0x80,

    /* U+0050 "P" */
    0xfc, 0xcd, 0x9b, 0x36, 0x6c, 0xd9, 0xb2, 0x78,
    0xc1, 0x83, 0x6, 0xc, 0x3c, 0x0,

    /* U+0051 "Q" */
    0x79, 0x9b, 0x36, 0x6c, 0xd9, 0xb3, 0x66, 0xcd,
    0x9b, 0x36, 0x6c, 0xd9, 0x9e, 0x7,

    /* U+0052 "R" */
    0xfc, 0x66, 0x66, 0x66, 0x66, 0x66, 0x64, 0x7c,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf7,

    /* U+0053 "S" */
    0x7e, 0x71, 0x8c, 0x71, 0x8e, 0x31, 0xc6, 0x31,
    0xcf, 0xc0,

    /* U+0054 "T" */
    0xff, 0x99, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c,

    /* U+0055 "U" */
    0xee, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3b,

    /* U+0056 "V" */
    0xf7, 0x62, 0x62, 0x62, 0x62, 0x62, 0x34, 0x34,
    0x34, 0x34, 0x34, 0x18, 0x18, 0x18, 0x18,

    /* U+0057 "W" */
    0xf7, 0x76, 0x62, 0x66, 0x26, 0x62, 0x66, 0x26,
    0x62, 0x33, 0x43, 0x34, 0x33, 0x43, 0x34, 0x37,
    0x41, 0x98, 0x19, 0x81, 0x98, 0x19, 0x80,

    /* U+0058 "X" */
    0xf7, 0x66, 0x66, 0x66, 0x34, 0x34, 0x34, 0x18,
    0x2c, 0x2c, 0x2c, 0x66, 0x66, 0x66, 0xef,

    /* U+0059 "Y" */
    0xf7, 0x62, 0x62, 0x62, 0x34, 0x34, 0x34, 0x34,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c,

    /* U+005A "Z" */
    0xfc, 0xc6, 0x33, 0x18, 0xcc, 0x63, 0x31, 0x8c,
    0x67, 0xe0,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x6d, 0xb6, 0xdb, 0x80,

    /* U+005C "\\" */
    0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20,
    0x84, 0x20,

    /* U+005D "]" */
    0xed, 0xb6, 0xdb, 0x6d, 0xb6, 0xdb, 0x6f, 0x80,

    /* U+005E "^" */
    0x21, 0x14, 0xa8, 0xc4,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0x78, 0x98, 0x30, 0x61, 0xcd, 0xb3, 0x66, 0xcd,
    0x99, 0xd8,

    /* U+0062 "b" */
    0xe0, 0xc1, 0x83, 0x7, 0xcc, 0xd9, 0xb3, 0x66,
    0xcd, 0x9b, 0x36, 0x6c, 0x9e, 0x0,

    /* U+0063 "c" */
    0x7e, 0x71, 0x8c, 0x63, 0x18, 0xc6, 0x5c,

    /* U+0064 "d" */
    0x1c, 0x18, 0x30, 0x67, 0xd9, 0xb3, 0x66, 0xcd,
    0x9b, 0x36, 0x6c, 0xd9, 0x9d, 0x80,

    /* U+0065 "e" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x6e, 0x30, 0xc3, 0x17,
    0x80,

    /* U+0066 "f" */
    0x3a, 0x58, 0xcf, 0xb1, 0x8c, 0x63, 0x18, 0xc6,
    0x33, 0xc0,

    /* U+0067 "g" */
    0x7f, 0x93, 0x36, 0x6c, 0xd9, 0xb3, 0x66, 0xcd,
    0x99, 0xf0, 0x60, 0xcf, 0x0,

    /* U+0068 "h" */
    0xe0, 0x60, 0x60, 0x60, 0x66, 0x6e, 0x76, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf7,

    /* U+0069 "i" */
    0x66, 0xe, 0x66, 0x66, 0x66, 0x66, 0x6f,

    /* U+006A "j" */
    0x33, 0x7, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31,
    0xe0,

    /* U+006B "k" */
    0xe0, 0x60, 0x60, 0x60, 0x67, 0x62, 0x64, 0x64,
    0x68, 0x78, 0x7c, 0x6c, 0x66, 0x66, 0xf7,

    /* U+006C "l" */
    0xe6, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf0,

    /* U+006D "m" */
    0xe6, 0x66, 0xee, 0x77, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf7,
    0x70,

    /* U+006E "n" */
    0xe6, 0x6e, 0x76, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0xf7,

    /* U+006F "o" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x37,
    0x80,

    /* U+0070 "p" */
    0xdc, 0xcd, 0x9b, 0x36, 0x6c, 0xd9, 0xb3, 0x66,
    0xc9, 0xe3, 0x6, 0x1e, 0x0,

    /* U+0071 "q" */
    0x75, 0x9b, 0x36, 0x6c, 0xd9, 0xb3, 0x66, 0xcd,
    0x99, 0xf0, 0x60, 0xc1, 0xc0,

    /* U+0072 "r" */
    0xdb, 0xd8, 0xc6, 0x31, 0x8c, 0x63, 0x3c,

    /* U+0073 "s" */
    0x7e, 0x71, 0x8e, 0x38, 0xe3, 0x1c, 0xfc,

    /* U+0074 "t" */
    0x26, 0xf2, 0x66, 0x66, 0x66, 0x66, 0x30,

    /* U+0075 "u" */
    0xee, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x3b,

    /* U+0076 "v" */
    0xf7, 0x62, 0x62, 0x62, 0x34, 0x34, 0x34, 0x34,
    0x18, 0x18, 0x18,

    /* U+0077 "w" */
    0xf7, 0x76, 0x62, 0x66, 0x26, 0x62, 0x33, 0x43,
    0x74, 0x37, 0x43, 0x74, 0x19, 0x81, 0x98, 0x19,
    0x80,

    /* U+0078 "x" */
    0xf7, 0x62, 0x62, 0x34, 0x34, 0x18, 0x2c, 0x2c,
    0x46, 0x46, 0xef,

    /* U+0079 "y" */
    0xf7, 0x62, 0x62, 0x62, 0x34, 0x34, 0x34, 0x34,
    0x18, 0x18, 0x18, 0x8, 0x38, 0x30,

    /* U+007A "z" */
    0xfc, 0xc6, 0x63, 0x31, 0x98, 0xc6, 0x7e,

    /* U+007B "{" */
    0x36, 0x66, 0x66, 0x66, 0x6c, 0x66, 0x66, 0x66,
    0x66, 0x30,

    /* U+007C "|" */
    0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xc6, 0x66, 0x66, 0x66, 0x63, 0x66, 0x66, 0x66,
    0x66, 0xc0,

    /* U+007E "~" */
    0x4d, 0x64
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 64, .box_w = 2, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 80, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 7, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 13, .adv_w = 112, .box_w = 5, .box_h = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 25, .adv_w = 208, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 48, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 63, .adv_w = 64, .box_w = 3, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 71, .adv_w = 64, .box_w = 3, .box_h = 19, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 79, .adv_w = 112, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 83, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 88, .adv_w = 64, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 89, .adv_w = 96, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 90, .adv_w = 64, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 112, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 96, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 112, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 112, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 112, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 112, .box_w = 6, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 64, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 64, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 216, .adv_w = 96, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 96, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 225, .adv_w = 96, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 112, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 144, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 144, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 112, .box_w = 5, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 144, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 112, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 112, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 144, .box_w = 6, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 80, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 96, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 112, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 192, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 144, .box_w = 6, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 128, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 144, .box_w = 7, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 477, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 96, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 208, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 570, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 585, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 600, .adv_w = 96, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 80, .box_w = 3, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 618, .adv_w = 112, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 80, .box_w = 3, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 636, .adv_w = 112, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 640, .adv_w = 80, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 641, .adv_w = 96, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 14},
    {.bitmap_index = 642, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 128, .box_w = 7, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 128, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 687, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 96, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 719, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 734, .adv_w = 80, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 741, .adv_w = 80, .box_w = 4, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 750, .adv_w = 144, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 765, .adv_w = 80, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 773, .adv_w = 208, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 810, .adv_w = 144, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 823, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 836, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 843, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 850, .adv_w = 80, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 868, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 192, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 896, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 907, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 921, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 928, .adv_w = 96, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 938, .adv_w = 48, .box_w = 1, .box_h = 20, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 941, .adv_w = 96, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 951, .adv_w = 112, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 34,
    3, 43,
    8, 34,
    8, 43,
    13, 3,
    13, 8,
    15, 3,
    15, 8,
    34, 3,
    34, 8,
    34, 53,
    34, 55,
    34, 56,
    34, 58,
    35, 53,
    35, 58,
    37, 53,
    37, 58,
    39, 13,
    39, 15,
    39, 34,
    39, 66,
    40, 53,
    40, 58,
    45, 3,
    45, 8,
    45, 53,
    45, 55,
    45, 56,
    45, 58,
    48, 53,
    48, 58,
    49, 13,
    49, 15,
    50, 53,
    50, 58,
    51, 53,
    51, 58,
    52, 66,
    52, 68,
    52, 69,
    52, 70,
    52, 72,
    52, 80,
    52, 82,
    52, 91,
    53, 13,
    53, 15,
    53, 34,
    53, 48,
    53, 53,
    53, 58,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 74,
    53, 78,
    53, 79,
    53, 80,
    53, 83,
    53, 84,
    53, 86,
    53, 91,
    54, 53,
    54, 58,
    55, 13,
    55, 15,
    55, 34,
    55, 55,
    55, 56,
    55, 58,
    56, 13,
    56, 15,
    56, 34,
    56, 55,
    56, 56,
    56, 58,
    58, 13,
    58, 15,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 48,
    58, 50,
    58, 55,
    58, 56,
    58, 58,
    58, 66,
    67, 71,
    67, 73,
    67, 74,
    67, 75,
    67, 76,
    67, 77,
    67, 78,
    67, 79,
    67, 81,
    67, 83,
    67, 85,
    67, 86,
    70, 66,
    70, 71,
    70, 73,
    70, 74,
    70, 75,
    70, 76,
    70, 77,
    70, 78,
    70, 79,
    70, 81,
    70, 83,
    70, 85,
    70, 86,
    71, 13,
    71, 15,
    71, 66,
    71, 71,
    71, 85,
    71, 87,
    71, 88,
    76, 85,
    80, 73,
    80, 74,
    80, 75,
    80, 76,
    80, 77,
    80, 78,
    80, 79,
    80, 81,
    80, 83,
    80, 85,
    80, 86,
    81, 73,
    81, 74,
    81, 75,
    81, 76,
    81, 77,
    81, 78,
    81, 79,
    81, 81,
    81, 83,
    81, 85,
    81, 86,
    84, 71,
    84, 73,
    84, 74,
    84, 75,
    84, 76,
    84, 77,
    84, 78,
    84, 79,
    84, 81,
    84, 83,
    84, 85,
    84, 86,
    85, 67,
    85, 68,
    85, 69,
    85, 70,
    85, 72,
    85, 89,
    87, 66,
    87, 71,
    87, 73,
    87, 74,
    87, 75,
    87, 76,
    87, 77,
    87, 78,
    87, 79,
    87, 81,
    87, 83,
    87, 85,
    87, 86,
    88, 66,
    88, 71,
    88, 73,
    88, 75,
    88, 76,
    88, 77,
    88, 78,
    88, 79,
    88, 81,
    88, 83,
    88, 85,
    88, 86,
    89, 73,
    89, 76,
    89, 77,
    89, 86,
    90, 66,
    90, 71,
    90, 73,
    90, 75,
    90, 76,
    90, 77,
    90, 78,
    90, 79,
    90, 81,
    90, 83,
    90, 85,
    90, 86,
    91, 66,
    91, 71,
    91, 77,
    91, 84,
    91, 85
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -32, -16, -32, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -32, -32, -16, -16, -16, -16, 16, 16,
    16, 16, 16, 16, 16, 16, -16, -16,
    -16, -16, -32, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, 16, 16, 16,
    16, 16, 16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16, -16, -16, -16, -16, -16, -16, -16,
    -16
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 209,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t custom_font_22 = {
#else
lv_font_t custom_font_22 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if CUSTOM_FONT_22*/

