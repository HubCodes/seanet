#ifndef SEANET_TASK_QUEUE_H
#define SEANET_TASK_QUEUE_H

#include <stdbool.h>

#include "task.h"

struct task_queue;
typedef struct task_queue task_queue_t;

task_queue_t* task_queue_new(void);
void task_queue_delete(task_queue_t* self);
void task_queue_put(task_queue_t* self, task_t* task);
task_t* task_queue_get(task_queue_t* self);
bool task_queue_is_empty(task_queue_t* self);

#endif //SEANET_TASK_QUEUE_H
