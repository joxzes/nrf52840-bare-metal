#ifndef QUEUE_H
#define QUEUE_H

#include "nrf52840.h"

#define SIZE 8

struct fifo {
	uint8_t buffer[SIZE];
	uint8_t head;
	uint8_t tail;
	uint8_t count;
};

void fifo_init(struct fifo *fifo);
int fifo_push(struct fifo *fifo, uint8_t data);
int fifo_pop(struct fifo *fifo, uint8_t *data);

extern struct fifo event_fifo;

#endif