if(CONFIG_ZMK_DISPLAY AND CONFIG_NICE_VIEW_WIDGET_STATUS)
  zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)

  zephyr_library_sources(
    ./src/main.c
    ./src/fonts/custom_font_22.c
    ./src/fonts/custom_font_44.c
    ./src/images/background_0.c
    ./src/images/background_1.c
    ./src/images/background_2.c
    ./src/images/background_3.c
    ./src/images/background_4.c
    ./src/images/background_5.c
    ./src/images/background_6.c
    ./src/images/bluetooth_logo_outline.c
    ./src/images/bluetooth_logo_outlined.c
    ./src/images/bluetooth_logo.c
    ./src/images/usb_logo.c
    ./src/utils/draw_background.c
    ./src/utils/draw_battery.c
    ./src/utils/draw_bluetooth_logo_outline.c
    ./src/utils/draw_bluetooth_logo_outlined.c
    ./src/utils/draw_bluetooth_logo.c
    ./src/utils/draw_usb_logo.c
    ./src/utils/rotate_info_canvas.c
  )

  if(NOT CONFIG_ZMK_SPLIT OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    zephyr_library_sources(
      ./src/central/initialize_listeners.c
      ./src/central/render.c
    )
  else()
    zephyr_library_sources(
      ./src/peripheral/initialize_listeners.c
      ./src/peripheral/render.c
    )
  endif()
endif()
