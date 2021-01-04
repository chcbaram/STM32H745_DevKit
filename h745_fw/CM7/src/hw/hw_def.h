/*
 * hw_def.h
 *
 *  Created on: Dec 15, 2020
 *      Author: baram
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_


#include "def.h"
#include "bsp.h"



#define _USE_HW_FLASH
#define _USE_HW_QSPI



#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_UART
#define      HW_UART_MAX_CH         1

#define _USE_HW_BUTTON
#define      HW_BUTTON_MAX_CH       1

#define _USE_HW_SWTIMER
#define      HW_SWTIMER_MAX_CH      8

#define _USE_HW_CLI
#define      HW_CLI_CMD_LIST_MAX    32
#define      HW_CLI_CMD_NAME_MAX    16
#define      HW_CLI_LINE_HIS_MAX    4
#define      HW_CLI_LINE_BUF_MAX    128

#define _USE_HW_SDRAM
#define      HW_SDRAM_MEM_ADDR      0xD0000000
#define      HW_SDRAM_MEM_SIZE      (32*1024*1024)



#endif /* SRC_HW_HW_DEF_H_ */
