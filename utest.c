/*
 * utest.c
 *
 *  Created on: Oct 19, 2016
 *      Author: Clint Olsen
 */


#include "CircBuff.h"
#include "utest.h"

//Tests wraparound case and adding/removing items
Success wraparound(CircBuf *buf){
	//add 6 items, take away 3, then add three to test wrap around
	int i;
	//add 6
	for(i = 0;i < 6;i++){
		AddItemToBuffer(buf,0x01);
	}
	//remove 3
	uint8_t ret;
	for(i = 0;i < 3;i++){
		ret = RemoveItemFromBuffer(buf);
		if(ret != 0x01){
			return FAIL;
		}
	}
	//add 3 in order to wrap
	for(i = 0;i < 3;i++){
		AddItemToBuffer(buf,0x03);
	}

	if(buf->head != buf->buffer){
		return FAIL;
	}

	return PASS;
}

Success overfill(CircBuf *buf){
	//add 8 items
	int i;
	for(i = 0;i < 8;i++){
		AddItemToBuffer(buf,0x01);
	}

	//add 9th to overflow
	if(AddItemToBuffer == CB_NO_ERROR){
		return FAIL;
	}

	return PASS;
}

Success overempty(CircBuf *buf){
	if(RemoveItemFromBuffer(buf) == 1){
		return PASS;
	}
	return FAIL;
}

