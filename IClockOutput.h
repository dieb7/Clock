/*
 * IClockOutput.h
 *
 *  Created on: Aug 25, 2018
 *      Author: diebm
 */

#ifndef ICLOCKOUTPUT_H_
#define ICLOCKOUTPUT_H_

class IClockOutput {
public:
	IClockOutput() {}
	virtual ~IClockOutput() {}

	virtual void show(unsigned char hour, unsigned char minute, unsigned char second) = 0;
};

#endif /* ICLOCKOUTPUT_H_ */
