/*
 * fsm_manual.c
 *
 *  Created on: Oct 27, 2024
 *      Author: ASUS
 */
#include <fsm_manual.h>

void fsm_manual_run(){
	switch (status) {
		case MAN_RED:
			if ((timerRoad1_flag == 1) & (timerRoad2_flag ==1)){
				traffic_manualred();
				updateManualRedLedBuffer();
				setTimerRoad1(500);
				setTimerRoad2(500);
			}
			if (checkflag(0) == 1){
				status = MAN_YELLOW;
				currentred = initialduration;
				initialduration = currentyellow;
			}
			if (checkflag(1) == 1){
				if(currentred <= 99000){
					currentred += 1000;
				} else {
					currentred = 1000;
				}
			}
			if (checkflag(2) == 1){
				status = INIT;
			}
			break;
		case MAN_YELLOW:
			if ((timerRoad1_flag == 1) & (timerRoad2_flag ==1)){

				traffic_manualyellow();
				updateManualYellowLedBuffer();
				setTimerRoad1(500);
				setTimerRoad2(500);
			}
			if (checkflag(0) == 1){
				status = MAN_GREEN;
				currentyellow = initialduration;
				initialduration = currentgreen;
			}
			if (checkflag(1) == 1){
				if(currentyellow <= 99000 ){
					if (currentred > currentyellow + currentgreen){
						currentyellow += 1000;
					} else {
						currentyellow = currentred - currentgreen;
					}
				} else {
					currentyellow = 1000;
				}
			}
			if (checkflag(2) == 1){
				status = INIT;
			}
			break;
		case MAN_GREEN:
			if ((timerRoad1_flag == 1) & (timerRoad2_flag ==1)){
				traffic_manualgreen();
				updateManualGreenLedBuffer();
				setTimerRoad1(500);
				setTimerRoad2(500);
			}
			if (checkflag(0) == 1){
				status = INIT;
				currentgreen = initialduration;
				initialduration = 0;
			}
			if (checkflag(1) == 1){
				if (currentgreen <= 99000){
					if (currentred > (currentgreen + currentyellow)){
						currentgreen += 1000;
					} else {
						currentgreen = currentred - currentyellow;
					}
				} else {
					currentgreen = 1000;
				}

			}
			if (checkflag(2) == 1){
				status = INIT;
			}
			break;
		default:
			break;
	}
}

