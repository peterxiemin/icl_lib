#include <stdio.h>
#include <stdlib.h>

/*
 * icl_thread.h
 *
 *  Created on: 2014年9月2日
 *      Author: peterxm
 */


#ifndef _ICL_THREAD_H_
#define _ICL_THREAD_H_

#include <stdio.h>
#include <pthread.h>
#include "icl_time.h"
/* static or stack pthread_cond_t */
#define ICL_PTHREAD_COND_INITIALIZER PTHREAD_COND_INITIALIZER
/* static or stack pthread_mutex_t */
#define ICL_PTHREAD_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER

/* cleanup function will exec with thoes condition:
 * 1.call pthread_exit
 * 2.other pthread call pthread_cancel()
 * 3.pthread_cleanup_pop(execute) execute is not zero
 * notice : push and pop must be pair 
 */

#define  icl_pthread_cleanup_push pthread_cleanup_push
#define  icl_pthread_cleanup_pop  pthread_cleanup_pop

int icl_pthread_equal(pthread_t td1, pthread_t td2);
pthread_t icl_pthread_self(void);
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

int icl_pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int icl_pthread_mutex_destory(pthread_mutex_t *mutex);
int icl_pthread_mutex_lock(pthread_mutex_t *mutex);
int icl_pthread_mutex_trylock(pthread_mutex_t *mutex);
int icl_pthread_mutex_unlock(pthread_mutex_t *mutex);

int icl_pthread_rwlock_init(pthread_rwlock_t *rwlock, const pthread_rwlockattr_t *attr);
int icl_pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
int icl_pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int icl_pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
int icl_pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
int icl_pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
int icl_pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);

int icl_pthread_cond_init(pthread_cond_t *cond, pthread_condattr_t *attr);
int icl_pthread_cond_destroy(pthread_cond_t *cond);
int icl_pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int icl_pthread_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex, const TimeSpec *timeout);
int icl_pthread_cond_signal(pthread_cond_t *cond);
int icl_pthread_cond_broadcast(pthread_cond_t *cond);

int icl_pthread_equal(pthread_t td1, pthread_t td2);
pthread_t icl_pthread_self(void);
int icl_pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

void icl_pthread_exit(void *rval_ptr);
int icl_pthread_join(pthread_t thread, void **rval_ptr);
int icl_pthread_detach(pthread_t thread);
int icl_pthread_cancel(pthread_t tid);



#endif
