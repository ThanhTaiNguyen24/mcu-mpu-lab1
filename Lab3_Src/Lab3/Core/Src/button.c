/*
 * button.c
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */


#include <button.h>
#include <main.h>


GPIO_TypeDef* portB[number_of_buttons] = {GPIOB, GPIOB, GPIOB};
uint16_t buttons[number_of_buttons] = {GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};

int button_flag[number_of_buttons] = {0, 0, 0};

int keyReg0[number_of_buttons];
int keyReg1[number_of_buttons];
int keyReg2[number_of_buttons];
int keyReg3[number_of_buttons];


int button_pressed_counter[number_of_buttons] = {100, 100, 100};


int checkflag(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}


void getKeyInput(void) {
	for(int i = 0; i < number_of_buttons; i++){
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		keyReg2[i] = HAL_GPIO_ReadPin(portB[i], buttons[i]);

		if ((keyReg0[i] == keyReg1[i])&&(keyReg1[i] == keyReg2[i])) {
			if (keyReg3[i] != keyReg2[i]){
				keyReg3[i] = keyReg2[i];
				if (keyReg2[i] <= pressed_button){
					button_pressed_counter[i] = 100;
		            button_flag[i] = 1;
		        }
		    } else {
		    	 button_pressed_counter[i]--;
		         if (button_pressed_counter[i] <= 0){
		        	 keyReg3[i] = normal_button;
		         }
		    }
		}
	}
}




