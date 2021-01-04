/*
 * hw.c
 *
 *  Created on: Dec 15, 2020
 *      Author: baram
 */




#include "hw.h"

  uint8_t  version_str[32];
  uint8_t  board_str  [32];
  uint8_t  name_str   [32];
  uint8_t  date_str   [32];
  uint8_t  time_str   [32];
  uint32_t addr_tag;
  uint32_t addr_fw;

__attribute__((aligned(2048))) __attribute__((section(".tag"))) flash_tag_t fw_tag =
    {
     // fw info
     //
     .magic_number = 0xAAAA5555,        // magic_number
     .version_str  = "V201215R1",       // version_str
     .board_str    = "H745_DevKit",     // board_str
     .name_str     = "Firmware",        // name
     .date_str     = __DATE__,
     .time_str     = __TIME__,
     //.addr_tag     = (uint32_t)&_flash_tag_addr,
     //.addr_fw      = (uint32_t)&_flash_fw_addr,


     // tag info
     //
    };



void hwInit(void)
{
  bspInit();

  cliInit();
  swtimerInit();

  ledInit();
  buttonInit();
  uartInit();
  uartOpen(_DEF_UART1, 57600);

  logPrintf("\n\n[ Firmware Begin... ]\r\n");
  logPrintf("Booting..Board\t\t: %s\r\n", fw_tag.board_str);
  logPrintf("Booting..Name \t\t: %s\r\n", fw_tag.name_str);
  logPrintf("Booting..Ver  \t\t: %s\r\n", fw_tag.version_str);
  logPrintf("Booting..Clock\t\t: %d Mhz\r\n", (int)HAL_RCC_GetSysClockFreq()/1000000);


  sdramInit();
  qspiInit();
  flashInit();

}
