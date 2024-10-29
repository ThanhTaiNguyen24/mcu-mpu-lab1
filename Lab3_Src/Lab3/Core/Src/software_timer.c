/*
 * software_timer.c
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#include "software_timer.h"


int timerRoad1_counter = 0;
int timerRoad2_counter = 0;
int timer2_counter = 0;


int timerRoad1_flag = 0;
int timerRoad2_flag = 0;
int timer2_flag = 0;




void setTimerRoad1(int duration){
	timerRoad1_counter = duration/timercycle;
	timerRoad1_flag = 0;
}

void setTimerRoad2(int duration){
	timerRoad2_counter = duration/timercycle;
	timerRoad2_flag = 0;
}

void setTimer2(){
	timer2_counter = (1000 / MAX_LED) / timercycle;
	timer2_flag = 0;
}

void timerRun(){
	if (timerRoad1_counter > 0){
		timerRoad1_counter--;
		if(timerRoad1_counter <= 0){
			timerRoad1_flag = 1;
		}
	}
	if (timerRoad2_counter > 0){
		timerRoad2_counter--;
		if(timerRoad2_counter <= 0){
			timerRoad2_flag = 1;
		}
	}
	if (timer2_counter > 0){
		timer2_counter--;
		road1duration-=10;
		road2duration-=10;
		if(timer2_counter <= 0){
			timer2_flag = 1;
		}
	}
}

