
#include "kernel.h"
#include "type.h"

void main() {
	MESSAGE msg;
	int ticks = 1;
	//syscall_char_printer('Z');
	while (1) {
		for (int i = 0; i < 4096000; i++) {} 
		//syscall_sendrec(RECEIVE, TASK_1, &msg);
		msg.RETVAL = ticks++;
		//syscall_int_printer(msg.RETVAL);
		syscall_sendrec(SEND, TASK_1, &msg);
		//syscall_int_printer(4);
	}
}