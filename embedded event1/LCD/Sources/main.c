/*
Author  - Gursimran singh
Team - XLNC
Date - 23/6/2010
*/

#include <hidef.h>      /* common defines and macros */
#include <mc9s12xdt512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12xdt512"
#include "LCD.h"
#include  <stdint.h>



void main(void) {
  /* put your own code here */
  EnableInterrupts;
  LCDInit();
  LCDPutString("XLNX");



int8_t a;

  for(;;) {} /* wait forever */
  /* please make sure that you never leave this function */
}
