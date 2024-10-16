#include "../../include/images/bluetooth_logo.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BLUETOOTH_LOGO
#define LV_ATTRIBUTE_IMG_BLUETOOTH_LOGO
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BLUETOOTH_LOGO uint8_t bluetooth_logo_map[] = {
  0xfe, 0xfe, 0xfe, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x0f, 0x00,
  0x3f, 0xc0,
  0x7f, 0xe0,
  0x7b, 0xe0,
  0xf9, 0xf0,
  0xfa, 0xf0,
  0xeb, 0x70,
  0xf2, 0xf0,
  0xf9, 0xf0,
  0xf2, 0xf0,
  0xeb, 0x70,
  0xfa, 0xf0,
  0xf9, 0xf0,
  0x7b, 0xe0,
  0x7f, 0xe0,
  0x3f, 0xc0,
  0x0f, 0x00,
};

const lv_img_dsc_t bluetooth_logo = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 12,
  .header.h = 17,
  .data_size = 42,
  .data = bluetooth_logo_map,
};
