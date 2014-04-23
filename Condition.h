/*
 * Condition.h
 *
 *  Created on: 2014年4月22日
 *      Author: yaochi
 */

#ifndef CONDITION_H_
#define CONDITION_H_
#include "MutexLock.h"

class Condition: public noncopyable {
public:
	Condition(MutexLock *p_lock);
	virtual ~Condition();
	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock *_p_lock;
};

#endif /* CONDITION_H_ */
