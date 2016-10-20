/*
 * utest.h
 *
 *  Created on: Oct 19, 2016
 *      Author: Clint Olsen
 */
#include "CircBuff.h"

#ifndef UTEST_H_
#define UTEST_H_

typedef enum Success_t{
	FAIL = 0,
	PASS = 1
}Success;

Success overfill(CircBuf *buf);
Success overempty(CircBuf *buf);
Success wraparound(CircBuf *buf);



#endif /* UTEST_H_ */
