#include "circular.h"
#include <stdlib.h>
/*
 * This file describes a circular buffer array for use with quote structs.
 * It holds 5 minutes of quotes, removing any that have expired. If necessary,
 * it will automatically expand if more space is needed, but the 5 minute
 * storage limit has not been met.
 */

static cbuf* head = 0;  //reference to head of circular array
static cbuf* tail = 0;  //reference to last filled node of circular array
static int size = 0;           //number of values contained in structure
static int capacity = 0;       //number of indices allocated for circular array


/*
 * First define what the real _cbuf struct should look like. Remember,
 * this is opaque to the users of your library so you can do whatever
 * you like in here. The _cbuf struct is typedefd in the header to the
 * cbuf type so you're free to use either type mostly
 * interchangably. The one exception is that sizeof calls must use the
 * _cbuf type.
 *
 * quote data - contains the quote data held in each buffer index
 */

struct _cbuf {
    quote data;
};

/*
 * Now define your implementations of all of the functions given in
 * the header. The test programs will not link successfully until each
 * function they use is defined here.
 */

/*
 * Initialize a circular buffer and return a pointer that can be used
 * to specify that circular buffer in future function calls.
 */
cbuf* cbuf_alloc(){
    head = malloc(10 * sizeof(cbuf));
    tail = head;
    return head;
}

/*
 * Deallocate all dynamically allocated memory associated with the
 * circular buffer referenced by cb_ptr. The programmer using your ADT
 * promises to never use the value in cb_ptr again.
 */
void cbuf_free(cbuf *cb_ptr){
    free(cb_ptr);
    size = 0;
    capacity = 0;
}

/*
 * Add a new currency exchange quote to the specified circular
 * buffer. The time is in seconds since midnight. This function should
 * remove any quotes in the circular buffer that are more than 5
 * minutes older than this quote. You should assume that the
 * timestamps given to cbuf_update() are in non-decreasing
 * order. During a cbuf_update(), the memory for the circular buffer
 * may have to grow or shrink according to the rules given in the
 * project description.
 */
void cbuf_update(cbuf *cb_ptr, unsigned int time, double rate){
    
}

/*
 * Return the average exchange rate of the quotes currently stored in
 * the buffer.
 */
double cbuf_average(cbuf *cb_ptr){
    return 0;
}

/*
 * Return a pointer to the earliest quote currently stored in the
 * buffer. (Earliest = smallest timestamp) The programmer using your
 * ADT promises to just "look at" the quote and not alter it in any
 * way.
 */
const quote *cbuf_start(cbuf *cb_ptr){
    return 0;
}

/*
 * Return a pointer to the latest quote currently stored in the
 * buffer. (Latest = largest timestamp) The programmer using your ADT
 * promises to just "look at" the quote and not alter it in any way.
 */
const quote *cbuf_end(cbuf *cb_ptr){
    return 0;
}

/*
 * Return the number of elements currently stored in the circular
 * buffer.
 */
size_t cbuf_size(cbuf *cb_ptr){
    return 0;
}

/*
 * Return the current capacity of the circular buffer (will be greater
 * than or equal to the number of elements in the buffer). When
 * cbuf_size(x) == cbuf_capacity(x) then your circular buffer may need
 * to grow when the next element is inserted.
 */
size_t cbuf_capacity(cbuf *cb_ptr){
    return 0;
}