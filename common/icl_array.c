/*
 * author: xiemin
 * file_name: icl_array.c
 * company: ifeng
 * date: 2014-09-29
 *
 */

#include <icl_array.h>

/*
 * ��create��init�϶�Ϊһ
 */
icl_array_t *icl_array_create(int n, int size) {
	icl_array_t *iat = malloc(sizeof(icl_array_t));
	iat->nelt = n;
	iat->elt_size = size;
	iat->pos = 0;
	iat->p = malloc(n * size);
	return iat;
}

void *icl_array_push_back(icl_array_t *iat) {
	if (iat == NULL) {
		printf("icl_array_t is NULL\n");
		return -1;
	}

	if (iat->pos >= iat->nelt) {
		icl_array_append(iat);
	}
	void *p = iat->p + (iat->elt_size * iat->pos);
	iat->pos++;
	return p;
}

/*
 * ����ռ䲻�㣬 ������һ��������
 */
int icl_array_append(icl_array_t *iat) {
	void *p = realloc(iat->p, iat->nelt * iat->elt_size * 2);
	/*
	 * ������Ҫע�⣬ �пӣ�
	 * ���ϵ�y���g����� realloc������ጷŵ�ԭ��Ŀ��g�������µĿ��g�� �@��һ��ԭ��ָ�
	 * ָ��ă��ݣ��͟oЧ�ˡ�acl��nginx���ò�ͬ�ķ�ʽ�@�^���@������
	 * ��ʹ�ù����У� �мɽ�����Ԫ�ص�ָ���ٴ����ã�����realloc�󣬱����ָ���쳣
	 */
	if (p == NULL) {
		return -1;
	}
	iat->p = p;
	return 0;
}

int icl_array_destroy(icl_array_t *iat) {
	void *p = iat->p;
	if (p) {
		free(p);
	}
	if (iat) {
		free(iat);
	}
	return 0;
}
