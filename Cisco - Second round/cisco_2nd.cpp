
//masivaku@cisco.com

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CIRCULAR_BUFFER_SIZE 10 // Totally ten elements in the circular buffer
#define ELEMENT_SIZE 8 // size of each item in circular buffer is 8 bytes

struct circular_buffer
{
    void *buffer_start;		// pointer to buffer start
    void *buffer_end;		// end of circular buffer
    int  max_elements;		// maximum number of items in circular buffer
    int count;     			// number of items at any given point in time in the circular buffer
    int element_size; 		// size of each item in the buffer
    void *head;    		    // pointer to a location at which new element is inserted into the buffer
    void *tail;      		// pointer to the location at which an element will be removed from the buffer
};


// initialize() returns true if everything is initialized successfully else false
int initialize(struct circular_buffer *circbuf, int size, int element_size)
{
	circbuf->buffer_start = malloc(size*element_size);
	// Here the size represents the maximum number of items in the circular buffer
	// so total number of bytes needed is max number of items * size of each item

	if (circbuf->buffer_start == NULL) {
		printf("Failure while allocating memory\n");
		return -1;
	}

	circbuf->buffer_end = (char *)circbuf->buffer_start + size*element_size; //typecasting buffer_start to char * as pointer arithmetic is done
	circbuf->max_elements = size;
	circbuf->element_size = element_size;
	circbuf->count = 0; // Initially there are no items in the circular buffer
	circbuf->head = circbuf->buffer_start;   // Items will be inserted at head
	circbuf->tail = circbuf->buffer_start;   // Items will be removed from tail

	return 0; //Indicating initialization is successful
}

// returns 0 if successful
// returns -1 if failure
int insert_last(struct circular_buffer *circbuf, void *element)
{
	if (circbuf->count == circbuf->max_elements) {
		printf("Circular buffer is full. No empty slots\n");
		return -1;
	}

	memcpy(circbuf->head, element, circbuf->element_size);
	circbuf->count++; //increment the count as one element is inserted

	circbuf->head = (char *) (circbuf->head) + circbuf->element_size;
	if (circbuf->head == circbuf->buffer_end) { // wrap to beginning if the head moves to end
		circbuf->head = circbuf->buffer_start;
	}

	return 0;
}

// returns 0 if successful
// returns -1 on trying to delete an item in an empty circular buffer
int remove_front(struct circular_buffer* circbuf, void* item)
{
	if (circbuf->count == 0) {
		printf("No elements in the circular buffer\n");
		return -1;
	}

	memcpy(item, circbuf->tail, circbuf->element_size);
	circbuf->count--; // decrement count by 1 as an element is removed

	circbuf->tail = (char *)circbuf->tail + circbuf->element_size;
	if (circbuf->tail == circbuf->buffer_end) { // wrap to beginning if the tail moves end
		circbuf->tail = circbuf->buffer_start;
	}

	return 0; // successfully removed an element at the front.
}

// Free up all the memory used by circular buffer
void free_circular_buffer(struct circular_buffer* circbuf)
{
    free(circbuf->buffer_start);
}


int main()
{
	struct circular_buffer *circbuf = (struct circular_buffer *)malloc(sizeof(struct circular_buffer));
	initialize(circbuf, CIRCULAR_BUFFER_SIZE, ELEMENT_SIZE);
	return 0;
}
