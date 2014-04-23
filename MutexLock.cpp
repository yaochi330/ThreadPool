/*
 * MutexLock.cpp
 *
 *  Created on: 2014年4月22日
 *      Author: yaochi
 */

#include "MutexLock.h"

MutexLock::MutexLock() {
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock() {
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock() {
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock() {
	pthread_mutex_unlock(&_mutex);
}
