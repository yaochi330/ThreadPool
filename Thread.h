/*
 * Thread.h
 *
 *  Created on: 2014年4月22日
 *      Author: yaochi
 */

#ifndef THREAD_H_
#define THREAD_H_
#include <pthread.h>

class Thread {
public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
	static void *thread_func(void *);
	virtual void run() = 0;
	pthread_t get_tid() const;
private:
	pthread_t _tid;
};

#endif /* THREAD_H_ */
