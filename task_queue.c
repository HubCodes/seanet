#include "task_queue.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct task_node {
    task_t* task;
    struct task_node* next;
} task_node_t;

struct task_queue {
    task_node_t* head;
    task_node_t* tail;
    int size;
};

static task_node_t* task_node_new(task_t* task);
static void task_node_delete(task_node_t* self);

task_queue_t* task_queue_new(void) {
    task_queue_t* self;

    self = calloc(1, sizeof(*self));
    return self;
}

void task_queue_delete(task_queue_t* self) {
    free(self);
}

void task_queue_put(task_queue_t* self, task_t* task) {
    task_node_t* task_node;

    task_node = task_node_new(task);
    if (task_queue_is_empty(self)) {
        self->tail = task_node;
        self->head = self->tail;
    } else {
        self->tail->next = task_node;
        self->tail = task_node;
    }
}

task_t* task_queue_get(task_queue_t* self) {
    task_node_t* node;
    task_t* result;

    if (self->head == NULL) {
        return NULL;
    }
    node = self->head;
    result = node->task;
    self->head = self->head->next;
    task_node_delete(node);
    return result;
}

bool task_queue_is_empty(task_queue_t* self) {
    return self->tail == NULL && self->head == NULL;
}

static task_node_t* task_node_new(task_t* task) {
    task_node_t* self;

    self = calloc(1, sizeof(*self));
    self->task = task;
    return self;
}

static void task_node_delete(task_node_t* self) {
    free(self);
}
