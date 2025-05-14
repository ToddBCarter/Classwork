/*   CS341  -- Operating System version 98.0       */
/*   Header file for os0main.c                     */

/* Procedure and function prototype declarations */

void  Create_process(int pid, char *name, int *addr);
void  Print_Welcome();
void  ipl_operating_system(int argc, char *argv[]);
void  read_parameter_file(int argc, char *argv[]);
int   parse_parameter(char *parameter);
void  debug_set();
void  debug_set_off();
void  Print_process_summary();
void  Print_transition(char *transition, int pid);
void  Print_PCB_information();
void  Print_ReadyQ();
void  Print_memory(int addr);
void  Print_instruction(int opcode, char *instruction);
void  Print_interrupt_list();
void  Core_Debug(int sig);

/*
 * These routines constitute the "operating system" itself
 * they are defined in os0.c
 */
void exceptions(int);
void interrupts(int);
void Timeout_process();
void Dispatch_process();
struct PCBitem * process_scheduler();
void Kill_process();

/* Constants for process states */
#define  READY       0
#define  RUNNING     1
#define  TERMINATED  2
#define  ZOMBIE      3    /* the ZOMBIE state marks unused process numbers */


/* process control block definiton */
struct  PCBitem
        {int  PC;         /* local PC for process */
         int  state;      /* current state of process */
         int  st_time;    /* time process started in state */
         int  run;        /* time process was in run state */
         int  ready;      /* time process was in ready state */
         int  loc;        /* memory loc of start of process */
         int  size;       /* size of process in words */
	 int proc;        /* process number */
         char name[30];   /* name of process */
	 struct PCBitem *next; /* Used to store address of next PCB */        
};

/*
 * These values are used to select the process scheduler algorithm:
 *    use 1 for FCFS
 *    use 2 for SJF
 *    use 3 for RR (default)
 */
#define   FCFS   1
#define   SJF    2
#define   RR     3


/* Version number constants */
#define   YEAR      2004
#define   VERSION    1
#define   REV       "a"


/* Length of names in the system */
#define   NAME_LENGTH  30

/*
 * A few global variables
 */

extern struct PCBitem  *current_pid;
extern int  live_processes;
extern int  number_of_processes;
extern int  memory_size;
extern struct PCBitem *PCB;
extern struct PCBitem *PCB_curr,*PCB_print;
extern struct PCBitem *PCB_head, *PCB_tail;
extern struct PCBitem *arr[];//Stores PCB address
extern int arr1[];//Stores processid for round robin algorithm 
extern int SCHEDULER;
extern int procid;
