/*
 * Condition.cpp
 *
 *  Created on: 2014年4月22日
 *      Author: yaochi
 */

#include "Condition.h"

Condition::Condition(MutexLock *p_lock) :
		_p_lock(p_lock) {
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition() {
	pthread_cond_destroy(&_cond);
}

void Condition::wait() {
	pthread_cond_wait(&_cond, &(_p_lock->_mutex));
}

void Condition::notify() {
	pthread_cond_signal(&_cond);
}

void Condition::notifyall() {
	pthread_cond_broadcast(&_cond);
}
