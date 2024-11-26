/*
 * commandparser.h
 *
 *  Created on: Nov 25, 2024
 *      Author: ASUS
 */

#ifndef INC_COMMANDPARSER_H_
#define INC_COMMANDPARSER_H_

#include "main.h"
#include "timer.h"
#include "stdio.h"
#include "string.h"


#define MAX_BUFFER_SIZE 30
#define INIT 	1
#define INFO	2

extern int state;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint32_t ADC_value ;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern char str[32];
void command_parser_fsm(void);
void uart_communiation_fsm(void);

#endif /* INC_COMMANDPARSER_H_ */
