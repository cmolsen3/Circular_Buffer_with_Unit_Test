#ifndef CIRCBUFF_H_
#define CIRCBUFF_H_
#include <stdint.h>

typedef struct CircBuf_t{
	volatile uint8_t *head;
	volatile uint8_t *tail;
	volatile uint32_t num_items;
	volatile uint32_t length;
	uint8_t *buffer;
}CircBuf;


typedef enum CB_Err_t {
	CB_MALLOC_FAILED = -3,
	CB_EMPTY = -2,
	CB_FULL =  -1,
	CB_NO_ERROR = 0,

} CB_Err;


CB_Err InitializeBuffer(CircBuf *buf, uint32_t length);
CB_Err ClearBuffer(CircBuf *buf);
CB_Err DeleteBuffer(CircBuf *buf);
CB_Err BufferFull(CircBuf *buf);
CB_Err BufferEmpty(CircBuf *buf);
CB_Err AddItemToBuffer(CircBuf *buf, uint8_t item);
uint8_t RemoveItemFromBuffer(CircBuf *buf);


#endif /* CIRCBUFF_H_ */
