/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            proto.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include "const.h"
#include "task.h"


/* klib.asm */
PUBLIC void	out_byte(u16 port, u8 value);
PUBLIC u8	in_byte(u16 port);
PUBLIC void	disp_str(char * info);
PUBLIC void disable_int();
PUBLIC void enable_int();

/* keyboard.c */
PUBLIC void init_keyboard();
PUBLIC void keyboard_read();

/* main.c */
PUBLIC void put_irq_handler(int irq, irq_handler handler);
PUBLIC void spurious_irq(int irq);
PUBLIC void panic(const char *fmt, ...);

/* klib.c */
PUBLIC void	delay(int time);
PUBLIC void disp_int(int input);

/* printf.c */
PUBLIC  int     printf(const char *fmt, ...);
#define	printl	printf

/* vsprintf.c */
PUBLIC  int     vsprintf(char *buf, const char *fmt, va_list args);
PUBLIC	int	sprintf(char *buf, const char *fmt, ...);

/* proc.c */
PUBLIC	void*	va2la(int pid, void* va);
PUBLIC 	int 	proc2pid(TASK* p);
PUBLIC	void	reset_msg(MESSAGE* p);
PUBLIC	void	dump_msg(const char * title, MESSAGE* m);
PUBLIC	void	dump_proc(TASK * p);
PUBLIC	int	send_recv(int function, int src_dest, MESSAGE* msg);

/* task.c */
PUBLIC void schedule_new();

/* tty.c */
PUBLIC int sys_printx(char* s);
PUBLIC int sys_write(char* s, int len);

/*klib.c*/
PUBLIC void sys_write_int_routine(int input);