/*
 * ClockTimeAdjuster.h
 *
 *  Created on: Aug 25, 2018
 *      Author: diebm
 */

#ifndef CLOCKTIMEADJUSTER_H_
#define CLOCKTIMEADJUSTER_H_

#include <ITask.h>
#include <IGpio.h>
#include "Clock.h"

class ClockTimeAdjuster: public ranetos::ITask {
	ranetos::IGpio * incrementHourButton;
	ranetos::IGpio * incrementMinuteButton;
	Clock * clock;
public:
	ClockTimeAdjuster() {
		incrementHourButton = nullptr;
		incrementMinuteButton = nullptr;
		clock = nullptr;
	}
	virtual ~ClockTimeAdjuster() {}

	ranetos::IGpio* getIncrementHourButton() {
		return incrementHourButton;
	}

	void setIncrementHourButton(ranetos::IGpio* incrementHourButton) {
		this->incrementHourButton = incrementHourButton;
	}

	ranetos::IGpio* getIncrementMinuteButton() {
		return incrementMinuteButton;
	}

	void setIncrementMinuteButton(ranetos::IGpio* incrementMinuteButton) {
		this->incrementMinuteButton = incrementMinuteButton;
	}

	Clock * getClock() {
		return this->clock;
	}

	void setClock(Clock * clock) {
		this->clock = clock;
	}

	void work();
};

#endif /* CLOCKTIMEADJUSTER_H_ */
