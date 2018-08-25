/*
 * Clock.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <ITask.h>
#include <Timer.h>
#include "ISystemClock.h"
#include "TimeCounter.h"

class Clock: public ranetos::ITask {
	ranetos::Timer & timer;
	TimeCounter hour;
	TimeCounter minute;
	TimeCounter second;
public:
	Clock(ranetos::Timer & timer): timer(timer) {
		hour.setLimit(23);
		minute.setLimit(59);
		second.setLimit(59);
		timer.setTimeOut(1000);
		timer.start();
	}
	virtual ~Clock() {}

	unsigned char currentHour() {
		return hour.getTimeCount();
	}

	unsigned char currentMinute() {
		return minute.getTimeCount();
	}

	unsigned char currentSecond() {
		return second.getTimeCount();
	}

	void incrementHour() {
		hour.increaseCount();
	}

	void incrementMinute() {
		minute.increaseCount();
		second.setTimeCount(0);
	}

	void work();
};

#endif /* CLOCK_H_ */

