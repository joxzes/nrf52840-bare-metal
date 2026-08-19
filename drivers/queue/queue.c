#include "queue.h"

struct fifo event_fifo;

void fifo_init(struct fifo *fifo)
{
	fifo->head = 0;
	fifo->tail = 0;
	fifo->count = 0;
}

int fifo_push(struct fifo *fifo, uint8_t data)
{
	if (fifo->count == SIZE)
		return 1;

	fifo->buffer[fifo->head] = data;
	fifo->head = (fifo->head + 1) % SIZE;
	fifo->count++;

	return 0;
}

int fifo_pop(struct fifo *fifo, uint8_t *data)
{
	if (!fifo->count)
		return 1;

	*data = fifo->buffer[fifo->tail];
	fifo->tail = (fifo->tail + 1) % SIZE;
	fifo->count--;

	return 0;
}