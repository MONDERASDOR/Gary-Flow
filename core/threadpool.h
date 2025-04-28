#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <pthread.h>
#include <stdint.h>

typedef struct ThreadPool ThreadPool;

ThreadPool* threadpool_create(int threads);
void threadpool_destroy(ThreadPool* pool);
void threadpool_add_task(ThreadPool* pool, void (*func)(void*), void* arg);

#endif // THREADPOOL_H
