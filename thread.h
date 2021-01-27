#ifndef SEANET_THREAD_H
#define SEANET_THREAD_H

#include "task_queue.h"

enum { MAX_WORKERS = 128 };

typedef struct supervisor {
    int id;
    int worker_count;
    task_queue_t* worker_queues[MAX_WORKERS];
} supervisor_t;

typedef struct worker {
    int id;
    task_queue_t* queue;
} worker_t;

#endif //SEANET_THREAD_H
