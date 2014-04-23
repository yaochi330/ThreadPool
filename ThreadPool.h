#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include <queue>
#include <vector>
#include "WorkThread.h"
#include "MutexLock.h"
#include "Condition.h"

struct Task
{
	int num;
};

class ThreadPool {
public:
	ThreadPool(std::vector<WorkThread>::size_type);
	~ThreadPool();

	void start_thread_pool();
	void stop_thread_pool();

	bool add_task(const Task &task);
	bool get_task(Task &task);

	bool is_task_queue_empty() const;
	std::queue<Task>::size_type get_task_queue_size() const;
private:
	std::queue<Task> _task_queue; //任务队列
	std::vector<WorkThread>::size_type _max_thread; //最多线程数目
	std::vector<WorkThread> _thread_vector; //存放线程

	bool _is_start; //标记线程池是否开启

	mutable MutexLock _lock; //保持任务队列的互斥操作
	mutable Condition _cond;
};

#endif /* THREADPOOL_H_ */
