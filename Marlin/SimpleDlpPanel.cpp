#include "SimpleDlpPanel.h"

#ifdef SIMPLE_DLP_PANEL
#include "Marlin.h"
#include "planner.h"
#include "pins.h"

static int homedelay = 0;     // counts up to SIMPLE_DLP_HOME_DELAY before accessing home.

/** LCD API **/
void lcd_init()
{
  SERIAL_ECHOLN("Got to Init");
  // Configure the I/O - all buttons are inputs with pullups.
  SET_INPUT(SIMPLE_DLP_PANEL_UP_PIN);
  SET_INPUT(SIMPLE_DLP_PANEL_DOWN_PIN);
  SET_INPUT(SIMPLE_DLP_PANEL_HOME_PIN);
  WRITE(SIMPLE_DLP_PANEL_UP_PIN,HIGH);
  WRITE(SIMPLE_DLP_PANEL_DOWN_PIN,HIGH);
  WRITE(SIMPLE_DLP_PANEL_HOME_PIN, HIGH);

}

void lcd_update()
{
  bool found = false;
  // Check - are any moves queued?
  if (movesplanned() == 0)
  {
    // Check for depressed buttons
    if (READ(SIMPLE_DLP_PANEL_UP_PIN) == 0)// && (pin_state & 0x1))
    {
      current_position[Z_AXIS] += SIMPLE_DLP_MOVE_DIST;
      SERIAL_ECHOLN("Up!");
      found = true;
    }
    if (READ(SIMPLE_DLP_PANEL_DOWN_PIN) == 0)// && (pin_state & 0x2))
    {
      current_position[Z_AXIS] -= SIMPLE_DLP_MOVE_DIST;
      //SERIAL_ECHOLN("Down!");
      found = true;
    }
    
    // execute the move, if a move was found
    if (found)
    {
      if (min_software_endstops && current_position[Z_AXIS] < Z_MIN_POS) current_position[Z_AXIS] = Z_MIN_POS;
      if (max_software_endstops && current_position[Z_AXIS] > Z_MAX_POS) current_position[Z_AXIS] = Z_MAX_POS;
      
      plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], homing_feedrate[Z_AXIS], active_extruder);
    }
    else if (READ(SIMPLE_DLP_PANEL_HOME_PIN) == 0)
    {
      if (homedelay++ > SIMPLE_DLP_HOME_DELAY)
      {
        //SERIAL_ECHOLN("HOME!");
        // Check for Home button pressed
        // enque the home Z command:
        enquecommand_P(PSTR("G28 Z0"));
        homedelay = 0;
      }
    }
    else
      homedelay = 0;
  }
}  
#endif // SIMPLE_DLP_PANEL