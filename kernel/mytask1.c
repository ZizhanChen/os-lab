
#include "kernel.h"
#include "type.h"

void main() {
	//syscall_int_printer(9);
	MESSAGE msg;
	while (1) {
		for (int i = 0; i < 4096000; i++) {}  // act as a delay
			//syscall_sendrec(SEND, TASK_0, &msg);
			//syscall_int_printer(msg.RETVAL);
			syscall_sendrec(RECEIVE, TASK_0, &msg);
			//syscall_int_printer(&msg);
			syscall_int_printer(msg.RETVAL);
			//syscall_char_printer('C');
			//syscall_int_printer(GET_TICKS);
			//syscall_int_printer(5);
	}
}