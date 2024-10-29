/*
 * software_timer.h
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"
#include "button.h"
#include "main.h"

extern int timerRoad1_flag;
extern int timerRoad1_counter;
extern int timerRoad2_flag;
extern int timerRoad2_counter;
extern int timer2_flag;
extern int timer2_counter;
extern int timer3_flag;
extern int timer3_counter;


void timerRun();
void setTimerRoad1(int duration);
void setTimerRoad2(int duration);
void setTimer2();
void setTimer3();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_SOFTWARE_TIMER_H_ */
