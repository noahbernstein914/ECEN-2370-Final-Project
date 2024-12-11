/*
 * Scheduler.h
 *
 *  Created on: Sep 10, 2024
 *      Author: noahbernstein
 */
#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>

#define LED_TOGGLE_EVENT (1 << 0)
#define DELAY_EVENT (1 << 1)
#define BUTTON_TOGGLE_EVENT (1 << 2)

uint32_t getScheduledEvents();

void addSchedulerEvent(uint32_t event);

void removeSchedulerEvent(uint32_t event);

#endif /* SCHEDULER_H_ */
