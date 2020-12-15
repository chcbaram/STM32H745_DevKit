/*
 * def.h
 *
 *  Created on: Oct 20, 2020
 *      Author: baram
 */

#ifndef SRC_COMMON_DEF_H_
#define SRC_COMMON_DEF_H_


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


#include "def_err.h"


#define _DEF_LED1                   0
#define _DEF_LED2                   1
#define _DEF_LED3                   2
#define _DEF_LED4                   3


#define _DEF_UART1                  0
#define _DEF_UART2                  1
#define _DEF_UART3                  2
#define _DEF_UART4                  3


#define _DEF_HIGH                   1
#define _DEF_LOW                    0


#define _DEF_LEFT                   0
#define _DEF_RIGHT                  1


#define _DEF_INPUT                  0
#define _DEF_INPUT_PULLUP           1
#define _DEF_INPUT_PULLDOWN         2
#define _DEF_OUTPUT                 3
#define _DEF_OUTPUT_PULLUP          4
#define _DEF_OUTPUT_PULLDOWN        5


#define _DEF_SPI1                   0
#define _DEF_SPI2                   1
#define _DEF_SPI3                   2
#define _DEF_SPI4                   3



typedef uint32_t  err_code_t;

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif


#ifndef map
#define map(value, in_min, in_max, out_min, out_max) ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
#endif


typedef struct
{
  uint32_t  ptr_in;
  uint32_t  ptr_out;
  uint32_t  length;
  uint8_t  *p_buf;
} ring_buf_t;


typedef struct
{
  uint32_t  ptr_in;
  uint32_t  ptr_out;
  uint32_t  length;
  uint16_t  *p_buf;
} ring_buf16_t;


typedef struct
{

  bool req;
  uint32_t  count;
} shared_buf_t;


typedef struct
{
  uint32_t addr;
  uint32_t end;
  uint32_t length;
} flash_attr_t;


typedef struct
{
  uint32_t magic_number;

  //-- fw info
  //
  uint8_t  version_str[32];
  uint8_t  board_str  [32];
  uint8_t  name_str   [32];
  uint8_t  date_str   [32];
  uint8_t  time_str   [32];
  uint32_t addr_tag;
  uint32_t addr_fw;
  uint32_t reserved   [32];

  //-- tag info
  //
  uint32_t tag_flash_type;
  uint32_t tag_flash_start;
  uint32_t tag_flash_end;
  uint32_t tag_flash_length;
  uint32_t tag_flash_crc;
  uint32_t tag_length;
  uint8_t  tag_date_str[32];
  uint8_t  tag_time_str[32];
} flash_tag_t;


#endif /* SRC_COMMON_DEF_H_ */
