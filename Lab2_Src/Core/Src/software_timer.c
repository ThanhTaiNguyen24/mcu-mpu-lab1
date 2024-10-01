/*
 * software_timer.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Admin
 */

#include "software_timer.h"
int timer1_counter = 0;
int timer2_counter = 0;
int timer3_counter = 0;
int timer4_counter = 0;
int timer5_counter = 0;

int timer1_flag = 1;
int timer2_flag = 1;
int timer3_flag = 1;
int timer4_flag = 1;
int timer5_flag = 1;

int TIMER_CYCLE = 10;

void setTimer1(int duration){
	timer1_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_counter = duration/TIMER_CYCLE;
	timer2_flag = 0;
}
void setTimer3(int duration){
	timer3_counter = duration/TIMER_CYCLE;
	timer3_flag = 0;
}

void timerRun(){
	if (timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
	if (timer2_counter > 0){
			timer1_counter--;
			if(timer1_counter <= 0){
				timer1_flag = 1;
			}
		}
	if (timer3_counter > 0){
			timer1_counter--;
			if(timer1_counter <= 0){
				timer3_flag = 1;
			}
		}
}
