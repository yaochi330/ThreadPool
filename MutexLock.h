/*
 * MutexLock.h
 *
 *  Created on: 2014年4月22日
 *      Author: yaochi
 */

#ifndef MUTEXLOCK_H_
#define MUTEXLOCK_H_
#include <pthread.h>
#include "noncopyable.h"
class Condition;
class MutexLock: public noncopyable {
friend class Condition;
public:
	MutexLock();
	virtual ~MutexLock();

	void lock();
	void unlock();
private:
	pthread_mutex_t _mutex;
};

#endif /* MUTEXLOCK_H_ */
