/*
 * icl_mem.c
 *
 *  Created on: 2014-1-24
 *      Author: peterxmw
 */

#include <stdio.h>
#include <stdlib.h>
#include "icl_mem.h"

void *icl_malloc(int len)
{
	return malloc(len);
}

void *icl_calloc(int count, int len)
{
	return calloc(count, len);
}

void *icl_realloc(void *ptr, int len)
{
	return realloc(ptr, len);
}

void *icl_free(void *ptr)
{
	free(ptr);
}


