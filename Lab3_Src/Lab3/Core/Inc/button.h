/*
 * button.h
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define normal_button GPIO_PIN_SET
#define pressed_button GPIO_PIN_RESET
#define number_of_buttons 3

int checkflag(int index);
void getKeyInput(void);


#endif /* INC_BUTTON_H_ */
