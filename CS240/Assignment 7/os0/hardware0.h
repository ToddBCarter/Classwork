/* Header file for hardware0.c      */

void execute_instructions();
void interrupt_check();
void hardware();
void start_io(int type, int process);

void Print_interrupt_list();
void Print_instruction(int opcode, char *instruction);

/* Constants for size of memory */
#define  MEMORY_SIZE  1024
#define  MAX            25

/* Constants for instructions used in execute_instructions */
#define  DONE    0
#define  INST    1
#define  NOOP    2

/* Constants for the exceptions */
#define  HALT     0
#define  NOOPEX   1
#define  ILLEGAL  2

/* Constants for the interrupts */
#define  OFF     0
#define  TIMER   1

/*
 * This is the interrupt event queue defintion.
 */
struct  interrupt_event
        {int  time;          /* time when interrupt will occur */
         int pid;           /* process ID that will receive the interrupt */
         struct  interrupt_event *forward;
        };

/*
 * The following variables are declared in hardware0.c, but used in other
 *  files/functions
 */

extern int Clock_Reg;
extern int PC_Reg;
extern int memory[];
extern int TIMESLICE;
extern struct  interrupt_event *interrupt_list;

