#ifndef	_TASK_H_
#define	_TASK_H_
#include "type.h"
#include "page.h"

typedef struct task_struct
{
	u32 pid;
	// address space (page directory)
	pte_t pg_dir;
	
	/* CPU-specific state of this task */
	u32 sp;
	u32 sp0;
	u32 ip;
	
	int nr_tty;
	int  p_flags;              /**
				    * process flags.
				    * A proc is runnable iff p_flags==0
				    */

	MESSAGE * p_msg;
	int p_recvfrom;
	int p_sendto;

	int has_int_msg;           /**
				    * nonzero if an INTERRUPT occurred when
				    * the task is not ready to deal with it.
				    */

	struct task_struct * q_sending;   /**
				    * queue of procs sending messages to
				    * this proc
				    */
	struct task_struct * next_sending;/**
				    * next proc in the sending
				    * queue (q_sending)
				    */
} TASK;

TASK tasks[2];
TASK* current;
TASK* prev;
TASK* next;

/* Number of tasks*/
#define NR_TASKS	2

#endif


