/*
 * wyf_array.c
 *
 *  Created on: 2014��1��23��
 *      Author: peterxiemin
 */


//#include "wyf_array.h"
//
//WYF_ARRAY* wyf_array_init(int n, int typsz)
//{
//	/*
//	 * ������ڴ����û������ ��ʱ����malloc��
//	 */
//	WYF_ARRAY *p;
//	p = (WYF_ARRAY*) malloc (sizeof(WYF_ARRAY));
//	if (p == NULL)
//	{
//		return NULL;
//	}
//	p->typsz = typsz;
//	p->size = typsz * n;
//	p->begin = malloc (p->size);
//	if (p->begin == NULL)
//	{
//		return NULL;
//	}
//	p->nelts = 0;
//	return p;
//}
//
//void* wyf_array_push(WYF_ARRAY *a)
//{
//	if ( a == NULL )
//		return NULL;
//	/*
//	 * �Ѿ����ˣ� ��Ҫ����
//	 */
//	if ( a->nelts*a->typsz >= a->size )
//	{
//		void *new = realloc(a->begin ,a->size * 2);
//		if (new == NULL)
//		{
//			return NULL;
//		}
//		a->begin = new;
//		a->size *= 2;
//	}
//	void *elts = a->begin + a->nelts * a->typsz;
//	a->nelts ++;
//	return elts;
//}
//
//void wyf_array_destroy(WYF_ARRAY *a)
//{
//	if (a == NULL)
//	{
//		return;
//	}
//	/* ����ҲӦ�ü����ڴ������� */
//	free(a->begin);
//	free(a);
//}