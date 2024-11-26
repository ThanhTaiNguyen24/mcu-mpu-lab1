/*
 * scheduler.h
 *
 *  Created on: Nov 25, 2024
 *      Author: ASUS
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

void SCH_Init(void);
void SCH_Update(void);
uint32_t SCH_Add_Task(void (*p_function)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(uint32_t TASK_ID);

#endif /* INC_SCHEDULER_H_ */
