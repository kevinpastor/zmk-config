#include "../../include/images/usb_logo.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_USB_LOGO
#define LV_ATTRIBUTE_IMG_USB_LOGO
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_USB_LOGO uint8_t usb_logo_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x00, 0x10, 0x00,
  0x00, 0xf8, 0x00,
  0x01, 0x10, 0x00,
  0xe2, 0x00, 0x80,
  0xff, 0xff, 0xc0,
  0xe0, 0x80, 0x80,
  0x00, 0x40, 0x00,
  0x00, 0x3c, 0x00,
  0x00, 0x0c, 0x00,
};

const lv_img_dsc_t usb_logo = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 18,
  .header.h = 9,
  .data_size = 35,
  .data = usb_logo_map,
};
