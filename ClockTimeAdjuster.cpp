/*
 * ClockTimeAdjuster.cpp
 *
 *  Created on: Aug 25, 2018
 *      Author: diebm
 */

#include "ClockTimeAdjuster.h"

void ClockTimeAdjuster::work() {
	if (!clock) {
		return;
	}

	bool changed = false;

	if (incrementHourButton && incrementHourButton->isOn()) {
		clock->incrementHour();
		changed = true;
	}

	if (incrementMinuteButton && incrementMinuteButton->isOn()) {
		clock->incrementMinute();
		changed = true;
	}

	if (changed) {
		IClockOutput * output = clock->getOutput();
		if (output) {
			unsigned char hour = clock->currentHour();
			unsigned char minute = clock->currentMinute();
			unsigned char second = clock->currentSecond();

			output->show(hour, minute, second);
		}
	}
}
