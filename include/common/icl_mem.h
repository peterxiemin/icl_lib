/*
 * icl_mem.h
 *
 *  Created on: 2014-1-24
 *      Author: peterxmw
 */

#ifndef ICL_MEM_H_
#define ICL_MEM_H_


void *icl_malloc(int len);

void *icl_calloc(int count, int len);

void *icl_realloc(void *ptr, int len);

void *icl_free(void *ptr);


#endif /* ICL_MEM_H_ */
