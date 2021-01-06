/*
 * hw.c
 *
 *  Created on: Dec 15, 2020
 *      Author: baram
 */




#include "hw.h"




void hwInit(void)
{
  bspInit();

  ledInit();

  if (qspiInit() == false)
  {
    while(1)
    {
     ledToggle(0);
     delay(100);
    }
  }
  flashInit();
}
