#pragma once

// Increase  backlight levels
#ifdef BACKLIGHT_LEVELS
  #undef BACKLIGHT_LEVELS
#endif

#ifdef BACKLIGHT_PIN
  #define BACKLIGHT_LEVELS 5
#endif
