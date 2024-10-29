/*
 * sevenSEG.c
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#include "sevenSEG.h"

uint8_t led7segment[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

const int MAX_LED = 2;
int index_led = 0;
int led_bufferRoad1 [2] = {0, 0};
int led_bufferRoad2 [2] = {0, 0};



void updateLedBuffer(){
	if (timer2_flag == 1){
	led_bufferRoad1[0] = (road1duration / 1000) / 10;
	led_bufferRoad1[1] = (road1duration / 1000) % 10;
	led_bufferRoad2[0] = (road2duration / 1000) / 10;
	led_bufferRoad2[1] = (road2duration / 1000) % 10;


	update7SEGRoad1(index_led);
	update7SEGRoad2(index_led);
	index_led++;
	if (index_led >= MAX_LED) index_led = 0;
	setTimer2();
	}
}
void updateManualRedLedBuffer(){
	if (timer2_flag == 1){
	led_bufferRoad1[0] = status / 10;
	led_bufferRoad1[1] = status % 10;
	led_bufferRoad2[0] = (currentred / 1000) / 10;
	led_bufferRoad2[1] = (currentred / 1000) % 10;

	update7SEGRoad1(index_led);
	update7SEGRoad2(index_led);
	index_led++;
	if (index_led >= MAX_LED) index_led = 0;
	setTimer2();
	}
}
void updateManualYellowLedBuffer(){
	if (timer2_flag == 1){
	led_bufferRoad1[0] = status / 10;
	led_bufferRoad1[1] = status % 10;
	led_bufferRoad2[0] = (currentyellow / 1000) / 10;
	led_bufferRoad2[1] = (currentyellow / 1000) % 10;

	update7SEGRoad1(index_led);
	update7SEGRoad2(index_led);
	index_led++;
	if (index_led >= MAX_LED) index_led = 0;
	setTimer2();
	}
}
void updateManualGreenLedBuffer(){
	if (timer2_flag == 1){
	led_bufferRoad1[0] = status / 10;
	led_bufferRoad1[1] = status % 10;
	led_bufferRoad2[0] = (currentgreen / 1000) / 10;
	led_bufferRoad2[1] = (currentgreen / 1000) % 10;

	update7SEGRoad1(index_led);
	update7SEGRoad2(index_led);
	index_led++;
	if (index_led >= MAX_LED) index_led = 0;
	setTimer2();
	}
}
void update7SEGRoad1 (int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		//led7segmentdisplay1(led_bufferRoad1[0]);
		display7SEGRoad1(led_bufferRoad1[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
		//led7segmentdisplay1(led_bufferRoad1[1]);
		display7SEGRoad1(led_bufferRoad1[1]);
		break;

	default:
		break;
	}
}

void update7SEGRoad2 (int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
		//led7segmentdisplay2(led_bufferRoad2[0]);
		display7SEGRoad2(led_bufferRoad2[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
		//led7segmentdisplay2(led_bufferRoad2[1]);
		display7SEGRoad2(led_bufferRoad2[1]);
		break;
	default:
		break;
	}
}
void display7SEGRoad1(int value)
{
	HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, SET);
	HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, SET);
	HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, SET);
	HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, SET);
	HAL_GPIO_WritePin(SEG_GPIO_Port, SEG4_Pin, SET);
	HAL_GPIO_WritePin(SEG_GPIO_Port, SEG5_Pin, SET);
	HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, SET);

	switch(value){
		case 0:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG5_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_GPIO_Port, SEG6_Pin, RESET);
			break;
		default:
			break;
	}
}
void display7SEGRoad2(int value)
{
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, SET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, SET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, SET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, SET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG14_Pin, SET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG15_Pin, SET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, SET);

	switch(value){
		case 0:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG14_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG15_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG14_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG15_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG15_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG14_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG15_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG14_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG15_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG13_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG15_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG16_Pin, RESET);
			break;
		default:
			break;
	}
}
//void led7segmentdisplay1 (uint8_t n){
//	uint8_t numberCode = led7segment[n];
//	uint32_t pin8 = GPIO_PIN_8;
//	for(uint8_t i = 0; i < 8 ; i++)
//	{
//		uint32_t pin = pin8 << i;
//		uint8_t value = (numberCode >> i) & 0x01;
//		HAL_GPIO_WritePin(GPIOA, pin , value);
//	}
//}
//
//void led7segmentdisplay2 (uint8_t n){
//	uint8_t numberCode = led7segment[n];
//	uint32_t pin0 = GPIO_PIN_0;
//	for(uint8_t i = 0; i < 8 ; i++)
//	{
//		uint32_t pin = pin0 << i;
//		uint8_t value = (numberCode >> i) & 0x01;
//		HAL_GPIO_WritePin(GPIOB, pin , value);
//	}
//}

