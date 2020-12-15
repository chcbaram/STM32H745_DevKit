/*
 * hw.h
 *
 *  Created on: Dec 15, 2020
 *      Author: baram
 */

#ifndef SRC_HW_HW_H_
#define SRC_HW_HW_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"

#include "led.h"
#include "uart.h"
#include "button.h"
#include "swtimer.h"
#include "cmdif.h"
#include "sdram.h"
#include "flash.h"
#include "qspi.h"

void hwInit(void);


#ifdef __cplusplus
}
#endif


#endif /* SRC_HW_HW_H_ */
