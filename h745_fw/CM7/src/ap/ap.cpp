/*
 * ap.cpp
 *
 *  Created on: Dec 15, 2020
 *      Author: baram
 */




#include "ap.h"





void apInit(void)
{
  cliOpen(_DEF_UART1, 57600);
  uartOpen(_DEF_UART2, 57600);
}

void apMain(void)
{
  uint32_t pre_time;


  pre_time = millis();
  while(1)
  {
    cliMain();

    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }

    if (uartAvailable(_DEF_UART2) > 0)
    {
      uartPrintf(_DEF_UART2, "USB Rx : 0x%X\n", uartRead(_DEF_UART2));
    }
  }
}
