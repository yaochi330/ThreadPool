/*
 * Thread.cpp
 *
 *  Created on: 2014年4月22日
 *      Author: yaochi
 */

#include "Thread.h"

Thread::Thread() : _tid(0) {
}

Thread::~Thread() {
}

void Thread::start() {
	pthread_create(&_tid, NULL, thread_func, this);
}

void Thread::join() {
	pthread_join(_tid, NULL);
}

void *Thread::thread_func(void *arg) {
	Thread *p_thread = static_cast<Thread*>(arg);
	p_thread->run();
	return NULL;
}

pthread_t Thread::get_tid() const {
	return _tid;
}
