/*
 * global.h
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <software_timer.h>
#include <button.h>


#define INIT 1
#define AUTO_1RED_2RED 10
#define AUTO_1RED_2GREEN 20
#define AUTO_1RED_2YELLOW 30

#define AUTO_1RED_2RED1 40
#define AUTO_1YELLOW_2RED 50
#define AUTO_1GREEN_2RED 60

#define MAN_RED 2
#define MAN_YELLOW 3
#define MAN_GREEN 4

extern int status;
extern int road1duration;
extern int road2duration;
extern int currentred;
extern int currentgreen;
extern int currentyellow;
extern int increaseduration;
extern int increasecounter;
extern int initialduration;

#define timercycle 10


#endif /* INC_GLOBAL_H_ */
