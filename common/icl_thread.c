/*
 * icl_thread.c
 *
 *  Created on: 2014年9月2日
 *      Author: peterxm
 */
#include "icl_thread.h"


// lock
int icl_pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
{
	int ret = pthread_mutex_init(mutex, attr);
	if (ret != 0)
	{
		printf("pthread_mutex_init failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* sucess */
	return 0;
}

int icl_pthread_mutex_destory(pthread_mutex_t *mutex)
{
	int ret = pthread_mutex_destroy(mutex);
	if (ret != 0) {
		printf("pthread_mutex_destory failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* sucess */
	return 0;
}

int icl_pthread_mutex_lock(pthread_mutex_t *mutex)
{
	int ret = pthread_mutex_lock(mutex);
	if (ret != 0) {
		printf("pthread_mutex_lock failed (%d, %s)\n", ret , strerror(ret));
		return -1;
	}
	/* sucess */
	return 0;
}

int icl_pthread_mutex_trylock(pthread_mutex_t *mutex)
{
	int ret = pthread_mutex_trylock(mutex);
	if (ret != 0) {
		/* none block */
		printf("pthread_mutex_trylock failed (%d, %s)\n", ret , strerror(ret));
		return -1;
	}
	return 0;
}

int icl_pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	int ret = pthread_mutex_unlock(mutex);
	if (ret != 0) {
		printf("pthread_mutex_unlock failed (%d, %s)\n", ret , strerror(ret));
		return -1;
	}
	/* sucess */
	return 0;

}

// rw lock 读写锁
int icl_pthread_rwlock_init(pthread_rwlock_t *rwlock,
								const pthread_rwlockattr_t *attr)
{
	int ret = pthread_rwlock_init(rwlock, attr);
	if (ret != 0) {
		printf("pthread_rwlock_init failed(%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_rwlock_destroy(pthread_rwlock_t *rwlock)
{
	int ret = pthread_rwlock_destroy(rwlock);
	if (ret != 0) {
		printf("pthread_rwlock_destroy failed(%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_rwlock_rdlock(pthread_rwlock_t *rwlock)
{
	int ret = pthread_rwlock_rdlock(rwlock);
	if (ret != 0) {
		printf("pthread_rwlock_rdlock failed.\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_rwlock_wrlock(pthread_rwlock_t *rwlock)
{
	int ret = pthread_rwlock_wrlock(rwlock);
	if (ret != 0) {
		printf("pthread_rwlock_wrlock failed.\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_rwlock_unlock(pthread_rwlock_t *rwlock)
{
	int ret = pthread_rwlock_unlock(rwlock);
	if (ret != 0) {
		printf("pthread_rwlock_unlock failed.\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock)
{
	int ret = pthread_rwlock_tryrdlock(rwlock);
	if (ret != 0) {
		/* no block */
		printf("pthread_rwlock_tryrdlock failed.\n", ret, strerror(ret));
		return -1;
	}
	return 0;
}

int icl_pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock)
{
	int ret = pthread_rwlock_trywrlock(rwlock);
	if (ret != 0) {
		/* no block */
		printf("pthread_rwlock_trywrlock failed.\n", ret, strerror(ret));
		return -1;
	}
	return 0;
}
//pthread_cond

int icl_pthread_cond_init(pthread_cond_t *cond,
								pthread_condattr_t *attr)
{
	int ret = pthread_cond_init(cond, attr);
	if (ret != 0) {
		printf("pthread_cond_init failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_cond_destroy(pthread_cond_t *cond)
{
	int ret = pthread_cond_destroy(cond);
	if (ret != 0) {
		printf("pthread_cond_destroy failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

/*
 * mutex的作用：
 * 保证pthread_cond_wait调用前后，不被其他线程影响
 * pthread_cond_wait 调用前，将mutex锁住，调用结束
 * 后，将mutex释放
 */
int icl_pthread_cond_wait(pthread_cond_t *cond, 
								pthread_mutex_t *mutex)
{
	int ret = pthread_cond_wait(cond, mutex);
	if (ret != 0) {
		printf("pthread_cond_wait failed(%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

/* TimeSpec is defined in icl_time */
int icl_pthread_cond_timedwait(pthread_cond_t *cond, 
								pthread_mutex_t *mutex,
								const TimeSpec *timeout)
{
	int ret = pthread_cond_timedwait(cond, mutex, timeout);
	if (ret != 0) {
		printf("pthread_cond_timedwait failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_cond_signal(pthread_cond_t *cond)
{
	int ret = pthread_cond_signal(cond);
	if (ret != 0) {
		printf("pthread_cond_signal failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_cond_broadcast(pthread_cond_t *cond)
{
	int ret = pthread_cond_broadcast(cond);
	if (ret != 0) {
		printf("pthread_cond_broadcast failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

// thread

int icl_pthread_equal(pthread_t td1, pthread_t td2)
{
	int ret =  pthread_equal(td1, td2);
	/* equal */
	if (ret == 0) {
		return 0;
	}
	/* not equal */
	else {
		return -1; 
	}
}


pthread_t icl_pthread_self(void)
{
	return pthread_self();
}

int icl_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
		void *(*start_routine) (void *), void *arg)
{
	int ret = pthread_create(thread, attr, start_routine, arg);
	/* success */
	if (ret == 0) {
		return 0;
	}
	else {
		printf("pthread_create failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
}

void icl_pthread_exit(void *rval_ptr)
{
	pthread_exit(rval_ptr);
}

/* programe default
 * if thread detach , ret is EINVAL
 * */
int icl_pthread_join(pthread_t thread, void **rval_ptr)
{
	int ret = pthread_join(thread, rval_ptr);
	if (ret != 0) {
		printf("can't join this thread(%s)\n", strerror(ret));
		return -1;
	}
	return 0;
}

int icl_pthread_detach(pthread_t thread) {
	int ret = pthread_detach(thread);
	if (ret != 0) {
		printf("pthread_detach failed (%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	/* success */
	return 0;
}

int icl_pthread_cancel(pthread_t tid)
{
	int ret = pthread_cancel(tid);
	/* failed */
	if (ret != 0) {
		printf("pthread_cancel failed(%d, %s)\n", ret, strerror(ret));
		return -1;
	}
	return 0;
}

