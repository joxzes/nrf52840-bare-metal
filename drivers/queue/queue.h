#ifndef QUEUE_H
#define QUEUE_H

#include "nrf52840.h"

void fifo_init(struct fifo *fifo);
int fifo_push(struct fifo *fifo, uint8_t data);
int fifo_pop(struct fifo *fifo, uint8_t *data);

extern struct fifo event_fifo;

#endif