#include "../../include/images/bluetooth_searching.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BLUETOOTH_SEARCHING
#define LV_ATTRIBUTE_IMG_BLUETOOTH_SEARCHING
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BLUETOOTH_SEARCHING uint8_t bluetooth_searching_map[] = {
  0xfe, 0xfe, 0xfe, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x0f, 0x00, 
  0x30, 0xc0, 
  0x40, 0x20, 
  0x40, 0x20, 
  0x82, 0x10, 
  0x81, 0x10, 
  0x89, 0x10, 
  0x84, 0x90, 
  0x94, 0x90, 
  0x84, 0x90, 
  0x89, 0x10, 
  0x81, 0x10, 
  0x82, 0x10, 
  0x40, 0x20, 
  0x40, 0x20, 
  0x30, 0xc0, 
  0x0f, 0x00, 
};

const lv_img_dsc_t bluetooth_searching = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 12,
  .header.h = 17,
  .data_size = 42,
  .data = bluetooth_searching_map,
};
