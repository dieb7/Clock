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
#include "IClockOutput.h"
#include "IClockAlarm.h"

class Clock: public ranetos::ITask {
	ranetos::Timer & timer;
	TimeCounter hour;
	TimeCounter minute;
	TimeCounter second;
	IClockOutput * output;
	IClockAlarm * alarm;
public:
	Clock(ranetos::Timer & timer): timer(timer) {
		hour.setLimit(23);
		minute.setLimit(59);
		second.setLimit(59);
		timer.setTimeOut(1000);
		timer.start();
		output = nullptr;
		alarm = nullptr;
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

	IClockOutput* getOutput() {
		return output;
	}

	void setOutput(IClockOutput *output) {
		this->output = output;
	}

	IClockAlarm* getAlarm() {
		return alarm;
	}

	void setAlarm(IClockAlarm* alarm) {
		this->alarm = alarm;
	}
};

#endif /* CLOCK_H_ */

