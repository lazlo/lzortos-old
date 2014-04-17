#ifndef D_SCHED_H
#define D_SCHED_H

void sched_init(void);

int sched_task_add(void (*fp)(void), const int delay, const int periode);

void sched_start(void);

void sched_update(void);

void sched_dispatch_tasks(void);

#endif /* D_SCHED_H */
