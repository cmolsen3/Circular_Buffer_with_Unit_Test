#include "CircBuff.h"
#include <stdint.h>
#include <stdlib.h>


CB_Err InitializeBuffer(CircBuf *buf, uint32_t length){

	buf->buffer = (uint8_t *)malloc(length);
	if(buf->buffer == NULL){
		return CB_MALLOC_FAILED;
	}
	buf->head = buf->buffer;
	buf->tail = buf->buffer;
	buf->num_items = (uint32_t)0;
	buf->length = length;

	return CB_NO_ERROR;
}

CB_Err ClearBuffer(CircBuf *buf){
	buf->num_items = 0;
	//buf->head = buf->buffer;
	//buf->tail = buf->buffer;
	return CB_NO_ERROR;
}

CB_Err DeleteBuffer(CircBuf *buf){
	free(buf->buffer);
	return CB_NO_ERROR;
}

CB_Err BufferFull(CircBuf *buf){
	if(buf->num_items == buf->length)
		return CB_FULL;
	else
		return CB_NO_ERROR;
}

CB_Err BufferEmpty(CircBuf *buf){
	if(buf->num_items == 0)
		return CB_EMPTY;
	else
		return CB_NO_ERROR;
}

CB_Err AddItemToBuffer(CircBuf *buf, uint8_t item){
	uint8_t *end = (uint8_t *)((uint32_t)buf->buffer + ((buf->length) - (uint32_t)1));
	if(BufferFull(buf)){
		return CB_FULL; //error
	}

	//Wrap Around Case
	if(end == buf->head){
		buf->head = buf->buffer;
		*(buf->head) = item;
	}
	//First Item Case
	else if(buf->num_items == 0){ //took out the buf->head == NULL
		*(buf->head) = item;
	}
	//Middle of Buffer Case
	else{
		buf->head += 1;
		*(buf->head) = item;
	}
	buf->num_items++;
	return CB_NO_ERROR;
}
uint8_t RemoveItemFromBuffer(CircBuf *buf){

	if(BufferEmpty(buf)){
			return 1;
		}

	uint8_t *end = (uint8_t *)((uint32_t)buf->buffer + ((buf->length) - (uint32_t)1));
	uint8_t *temp = (uint8_t *)buf->tail;
	uint8_t rv = 0x00;

	if(temp == end){
		rv = *(buf->tail);
		buf->tail = buf->buffer;
	}

	else{
		rv = *(buf->tail);
		buf->tail += 1;
	}
	if(buf->num_items != 0){
		buf->num_items--;
	}
	if(BufferEmpty(buf) == CB_EMPTY){
		buf->head = buf->buffer;
		buf->tail = buf->buffer;
	}
	return rv;
}

