// Very, very simple panel implementation for DLP printer.
// Ben W - 9/2015

#ifndef _SIMPLE_DLP_PANEL_H
#define _SIMPLE_DLP_PANEL_H

#include "Marlin.h"

#ifdef SIMPLE_DLP_PANEL
  #define SIMPLE_DLP_MOVE_DIST 0.1f		// mm to move with each button press.
  #define SIMPLE_DLP_HOME_DELAY 10000  // updates for which the button needs to be held down before homing begins. This prevents accidental homing.

  void lcd_update();
  void lcd_init();
  FORCE_INLINE void lcd_setstatus(const char* message) {}
  FORCE_INLINE void lcd_setstatuspgm(const char* message) {}
  FORCE_INLINE void lcd_setalertstatuspgm(const char* message) {}
  FORCE_INLINE void lcd_reset_alert_level() {}
  FORCE_INLINE bool lcd_detected(void) {return true;}

  FORCE_INLINE void lcd_buttons_update() {}

  FORCE_INLINE void lcd_buzz(long duration,uint16_t freq) {}

  #define LCD_MESSAGEPGM(x) 
  #define LCD_ALERTMESSAGEPGM(x) 

#endif //SIMPLE_DLP_PANEL

#endif //_SIMPLE_DLP_PANEL_H