#ifndef SEANET_TASK_H
#define SEANET_TASK_H

#include <ucontext.h>

typedef enum task_state {
    RUN,
    SUSPEND,
    END,
} task_state_t;

typedef struct task {
    struct ucontext_t ctxt;
    task_state_t state;
    void* executable;
} task_t;

#endif //SEANET_TASK_H
