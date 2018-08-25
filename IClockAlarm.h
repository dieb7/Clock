/*
 * IClockAlarm.h
 *
 *  Created on: Aug 25, 2018
 *      Author: diebm
 */

#ifndef ICLOCKALARM_H_
#define ICLOCKALARM_H_

class IClockAlarm {
public:
	IClockAlarm() {}
	virtual ~IClockAlarm() {}

	virtual void checkTime(unsigned char hour, unsigned char minute, unsigned char second) = 0;
};

#endif /* ICLOCKALARM_H_ */
