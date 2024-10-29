#include <fsm_automatic.h>

void checkManual(){
	updateLedBuffer();
	if (checkflag(0) == 1){
		initialduration = currentred;
		traffic_turnoffall();
		status = MAN_RED;
		setTimerRoad1(100);
		setTimerRoad2(100);
	}
}
void fsm_automatic_run(){
	switch (status) {
		case INIT:
			traffic_turnoffall();
			status = AUTO_1RED_2GREEN;

			road1duration = currentred;
			road2duration = currentgreen;

			setTimerRoad1(currentred);
			setTimerRoad2(currentgreen);
			setTimer2();

			break;
		case AUTO_1RED_2GREEN:
			traffic_1red_2green();
			checkManual();
			if (timerRoad2_flag == 1){
				status = AUTO_1RED_2YELLOW;
				road2duration = currentyellow;
				setTimerRoad2(currentyellow);
			}
			break;

		case AUTO_1RED_2YELLOW:
			traffic_1red_2yellow();
			checkManual();
			if ((timerRoad1_flag == 1) && (timerRoad2_flag == 1)){
				status = AUTO_1GREEN_2RED;
				road1duration = currentgreen;
				road2duration = currentred;
				setTimerRoad1(currentgreen);
				setTimerRoad2(currentred);

			}
			if (timerRoad2_flag == 1){
				status = AUTO_1RED_2RED;
				road2duration = currentred;
				setTimerRoad2(currentred);
			}
			break;
		case AUTO_1RED_2RED:
			traffic_1red_2red();
			checkManual();
			if (timerRoad1_flag == 1){
				status = AUTO_1GREEN_2RED;
				road1duration = currentgreen;
				setTimerRoad1(currentgreen);
			}

			break;

		case AUTO_1GREEN_2RED:
			traffic_1green_2red();
			checkManual();
			if (timerRoad1_flag == 1){
				status = AUTO_1YELLOW_2RED;

				road1duration = currentyellow;
				setTimerRoad1(currentyellow);
			}
			break;
		case AUTO_1YELLOW_2RED:
			traffic_1yellow_2red();
			checkManual();
			if((timerRoad1_flag == 1) && (timerRoad2_flag == 1)){
				status = AUTO_1RED_2GREEN;
				road1duration = currentred;
				road2duration = currentgreen;
				setTimerRoad1(currentred);
				setTimerRoad2(currentgreen);
			}
			if (timerRoad1_flag == 1){
				status = AUTO_1RED_2RED1;
				road1duration = currentred;
				setTimerRoad1(currentred);
			}
			break;
		case AUTO_1RED_2RED1:
			traffic_1red_2red();
			checkManual();
			if (timerRoad2_flag == 1){
				status = AUTO_1GREEN_2RED;
				road1duration = currentgreen;
				setTimerRoad1(currentgreen);
			}
			break;
		default:
			break;
	}
}
