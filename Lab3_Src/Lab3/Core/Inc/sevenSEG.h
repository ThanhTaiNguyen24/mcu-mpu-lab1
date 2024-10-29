/*
 * sevenSEG.h
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#ifndef INC_SEVENSEG_H_
#define INC_SEVENSEG_H_

#include "global.h"
#include "main.h"
#include "software_timer.h"


void updateLedBuffer();

void updateManualRedLedBuffer();
void updateManualYellowLedBuffer();
void updateManualGreenLedBuffer();

void update7SEGRoad1(int index);

void update7SEGRoad2(int index);

void display7SEGRoad1(int value);

void display7SEGRoad2(int value);

void led7segmentdisplay1 (uint8_t n);

void led7segmentdisplay2 (uint8_t n);

#endif /* INC_SEVENSEG_H_ */
