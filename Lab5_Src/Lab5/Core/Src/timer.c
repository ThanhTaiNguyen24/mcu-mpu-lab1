/*
 * timer.c
 *
 *  Created on: Nov 25, 2024
 *      Author: ASUS
 */



int timer_flag0;
int timer_flag1;

int timer_counter0;
int timer_counter1;

int TIMER_CYCLE = 10;

void setTimer0(int duration) {
	timer_counter0 = duration / TIMER_CYCLE;
	timer_flag0 = 0;
}


void setTimer1(int duration) {
	timer_counter1 = duration / TIMER_CYCLE;
	timer_flag1 = 0;
}


void timer_run() {
	if (timer_counter0 > 0) {
		timer_counter0--;
		if (timer_counter0 == 0) {
			timer_flag0 = 1;
		}
	}
	if (timer_counter1 > 0) {
		timer_counter1--;
		if (timer_counter1 == 0) {
			timer_flag1 = 1;
		}
	}

}
