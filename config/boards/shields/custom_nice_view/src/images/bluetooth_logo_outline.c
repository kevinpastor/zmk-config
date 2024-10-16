#include "../../include/images/bluetooth_logo_outline.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BLUETOOTH_LOGO_OUTLINE
#define LV_ATTRIBUTE_IMG_BLUETOOTH_LOGO_OUTLINE
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BLUETOOTH_LOGO_OUTLINE uint8_t bluetooth_logo_outline_map[] = {
  0xfe, 0xfe, 0xfe, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x0f, 0x00,
  0x30, 0xc0,
  0x40, 0x20,
  0x40, 0x20,
  0x80, 0x10,
  0x80, 0x10,
  0x80, 0x10,
  0x80, 0x10,
  0x80, 0x10,
  0x80, 0x10,
  0x80, 0x10,
  0x80, 0x10,
  0x80, 0x10,
  0x40, 0x20,
  0x40, 0x20,
  0x30, 0xc0,
  0x0f, 0x00,
};

const lv_img_dsc_t bluetooth_logo_outline = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 12,
  .header.h = 17,
  .data_size = 42,
  .data = bluetooth_logo_outline_map,
};
