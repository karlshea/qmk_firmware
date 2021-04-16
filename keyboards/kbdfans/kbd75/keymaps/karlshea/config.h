#pragma once

// Disable Caps Lock light
//#ifdef LED_CAPS_LOCK_PIN
//  #undef LED_CAPS_LOCK_PIN
//#endif

// Increase  backlight levels
#ifdef BACKLIGHT_LEVELS
  #undef BACKLIGHT_LEVELS
#endif

#ifdef BACKLIGHT_PIN

  // This is if caps is disabled entirely, to add the LED to backlight.
  //#undef BACKLIGHT_PIN
  //#define BACKLIGHT_PINS { B2, B6 }

  #define BACKLIGHT_LEVELS 20
#endif

// Disable rgb animations
#ifdef RGB_DI_PIN
  #undef RGBLIGHT_ANIMATIONS
#endif
