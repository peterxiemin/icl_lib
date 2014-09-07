/*
 * icl_array.h
 *
 *  Created on: 2014-1-27
 *      Author: peterxmw
 */

#ifndef ICL_ARRAY_H_
#define ICL_ARRAY_H_

typedef struct icl_array ICL_ARRAY;

struct icl_array {
	void *data;
	ICL_ARRAY *prev;
	ICL_ARRAY *next;
};

ICL_ARRAY* icl_array_init();

int icl_array_empty(ICL_ARRAY *h);

int icl_array_size(ICL_ARRAY *h);

int icl_array_push_back(ICL_ARRAY *h, void *d);

int icl_array_push_front(ICL_ARRAY *h, void *d);

ICL_ARRAY *icl_array_pop_back(ICL_ARRAY *h);

ICL_ARRAY *icl_array_pop_front(ICL_ARRAY *h);

int icl_array_clear(ICL_ARRAY *h);

#endif /* ICL_ARRAY_H_ */
