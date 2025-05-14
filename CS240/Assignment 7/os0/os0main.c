/*   CS341  -- Operating System version 98.0       */

#include  "os0main.h"
#include  "hardware0.h"
#include  <signal.h>
#include  <stdio.h> 

char STATES[4] = {'R','G','T','Z'};

/*
 * These debug constants are set via a parameter file that is provided
 * by the user. The default values are provided here.
 */
int   WELCOME = 1;
int   SUMMARY = 1;
int   INSTRUCTIONS = 1;
int   TRANSITIONS = 1;
int   MEMORY = 0;
int   INTERRUPTS = 0;
int   PCB_DEBUG = 0;

/*
 * Type of scheduler to use. Default is 3 (rr)
 */
int   SCHEDULER = 3;

/*
 * This constant is used to determine the time slice used during any
 *  round robin (RR) scheduling algorithm.
 */
int  TIMESLICE = 5;

/* The main program for the entire operating system.  Loads all process
 * files onto the virtual disk.  Calls ipl_operating system to create
 * processes and dispatch one.  Then calls hardware to start the machine
 * simulation running.  Hardware is in an infinite loop, interacting
 * with the operating system through a series of exceptions, interrupts,
 * and system calls.
 */



int main(int argc, char *argv[])
{
   read_parameter_file(argc, argv);
   Print_Welcome();
   ipl_operating_system(argc, argv);
   hardware();
   Print_process_summary();
   return 0;
}

/* 
 * Print a welcome to the system with various parameters such as version,
 *  date, etc. displayed
 */
void Print_Welcome()
{
 if (WELCOME)
  {/* Welcome everyone to the system */
   printf("Welcome to the CS Computer System model 341 ");
   printf("(version %d.%d%s)\n",YEAR,VERSION,REV);
   printf("Computer configuration:\n");
   printf("  MEMORY_SIZE: %d\n", MEMORY_SIZE);
   printf("  SCHEDULER (1=FCFS,2=SJF,3=RR): %d\n", SCHEDULER);
   if (SCHEDULER==3)
      {printf("  TIMESLICE: %d\n", TIMESLICE);
      }
  }
}


/* 
 * Creates all process and dispatches one of them
 */
void ipl_operating_system(int argc, char *argv[])
{char process[NAME_LENGTH];
 char c;
 int  i, addr;
 FILE *jfile;
/* Look for the name of the file containing a list of process names */
   if (argc < 2)
      {printf("ERROR: You must enter the name of the file that contains a\n");
       printf("list of all the process names that are to be run.\n");
       exit(1);
      }
   jfile = fopen(argv[1], "r");
   if (jfile == NULL)
      {printf("ERROR: Unable to open the job file %s\n", argv[1]);
       exit (1);
      }
/* Initialize the number of processes, registers, and clock  */
   live_processes = 0;
   Clock_Reg = 0;
   PCB_head = PCB_tail = NULL;

 /* Create all processes */
   addr = number_of_processes = 1;
   while (fscanf(jfile,"%s",process) != EOF)
      {Create_process(number_of_processes++, process, &addr);
      }
   fclose(jfile);
   memory_size = addr;
   Dispatch_process();
   Print_memory(memory_size);
}


/* 
 * Some constants used by the parser routines that follow
 */
#define  PAR_SCHEDULER     1
#define  PAR_TIMESLICE     2
#define  PAR_INSTRUCTIONS  3
#define  PAR_TRANSITIONS   4
#define  PAR_MEMORY        5
#define  PAR_INTERRUPTS    6
#define  PAR_PCB_DEBUG     7
#define  PAR_SUMMARY       8
#define  PAR_WELCOME      10


/* 
 * Reads a file that contains the values of parameters used by the hardware
 *  and software during this run.
 *
 *  Modified so that "parameters" file is opened and used as the default, if
 *  no parameters file is explicitly listed on the command line - RER 10/11/01
 *     
 */
void read_parameter_file(int argc, char *argv[])
{
 char   parameter[NAME_LENGTH];
 char   inputline[133];
 char   *paramfilename = "parameters";
 int    value, parse;
 char  *onechar;
 FILE  *pfile;
 int    i;
   /* 
    * Look for the name of the file containing a list of process names.
    * If the file name is DEBUG, then this is not a real file name, but
    * indicates that all of the debug flags are to be set to 1.
    * If the file name is DEBUGOFF, then turn off all debug flags except
    * Welcome and Summary. If there is no file name, then use the default
    * name "parameters"
    */
   if (argc > 2)
     {
      if (strcmp(argv[2],"DEBUG") == 0)
         debug_set();
      else if (strcmp(argv[2],"DEBUGOFF") == 0)
         debug_set_off();
      else
         paramfilename = argv[2];
     }

   pfile = fopen(paramfilename, "r");
   if (pfile == NULL)
     {
      printf("ERROR: Unable to open the parameter file %s\n",paramfilename);
      exit(1);
     }
   onechar = fgets(inputline, 133, pfile);
   while ( onechar != '\0' )
     {
      if (inputline[0] != '#')
        {
	 sscanf(inputline, "%s%d", parameter, &value);
         parse = parse_parameter(parameter);
         switch (parse)
           {
            case PAR_SCHEDULER:         SCHEDULER=value;
                                        break;
            case PAR_TIMESLICE:         TIMESLICE=value;
                                        break;
            case PAR_INSTRUCTIONS:      INSTRUCTIONS=value;
                                        break;
            case PAR_TRANSITIONS:       TRANSITIONS=value;
                                        break;
            case PAR_MEMORY:            MEMORY=value;
                                        break;
            case PAR_INTERRUPTS:        INTERRUPTS=value;
                                        break;
            case PAR_PCB_DEBUG:         PCB_DEBUG=value;
                                        break;
            case PAR_SUMMARY:           SUMMARY=value;
                                        break;
            case PAR_WELCOME:           WELCOME=value;
                                        break;
            default:                    break;
           } //end CASE
        } // end IF
           onechar = fgets(inputline, 133, pfile);
     } // end WHILE

   fclose(pfile);
   /* check the values of the parameters */
   if (SCHEDULER<1 || SCHEDULER>3)
     {
      printf("ERROR: SCHEDULER=%d, out of range. ",SCHEDULER);
      printf("It should be between 1 and 3.\n");
      exit(1);
     }
   if (TIMESLICE<0)
     {
      printf("ERROR: TIMESLICE=%d, out of range. ",TIMESLICE);
      printf("It should be greater than 0.\n");
      exit(1);
     }

   if (argc > 3)
     {
      if (strcmp(argv[3],"DEBUG") == 0)
	 debug_set();
      else if (strcmp(argv[3],"DEBUGOFF") == 0)
          debug_set_off();
     }

   /* create a signal handler for all possible signals */
   for (i=1;i<35;i++)
      signal(i, *Core_Debug);
      
} // END read_parameter_file


/* 
 * parse_parameter does a simple parse on a parameter name, returning
 * an integer that can be used in a switch statement
 */
int parse_parameter(char *parameter)
{
 if (strcmp(parameter, "INSTRUCTIONS") == 0)
    {return PAR_INSTRUCTIONS;
    }
 if (strcmp(parameter, "INTERRUPTS") == 0)
    {return PAR_INTERRUPTS;
    }
 if (strcmp(parameter, "MEMORY") == 0)
    {return PAR_MEMORY;
    }
 if (strcmp(parameter, "PCB") == 0)
    {return PAR_PCB_DEBUG;
    }
 if (strcmp(parameter, "SCHEDULER") == 0)
    {return PAR_SCHEDULER;
    }
 if (strcmp(parameter, "SUMMARY") == 0)
    {return PAR_SUMMARY;
    }
 if (strcmp(parameter, "TIMESLICE") == 0)
    {return PAR_TIMESLICE;
    }
 if (strcmp(parameter, "TRANSITIONS") == 0)
    {return PAR_TRANSITIONS;
    }
 if (strcmp(parameter, "WELCOME") == 0)
    {return PAR_WELCOME;
    }
 printf("ERROR: Parameter %s not understood. It will be ignored.\n", parameter);
 return 0;
}


/* 
 * sets all of the debug flags to 1. Used when DEBUG is passed to the
 * program as it starts
 */
void debug_set()
{
  WELCOME=1;
  INSTRUCTIONS=1;
  TRANSITIONS=1;
  MEMORY=1;
  INTERRUPTS=1;
  PCB_DEBUG=1;
  SUMMARY=1;
}


/* 
 * sets all of the debug flags to 0, except Welcome and Summary. Used when
 * DEBUGOFF is passed to the program as it starts
 */
void debug_set_off()
{
  WELCOME=1;
  SUMMARY=1;
  TRANSITIONS=0;
  MEMORY=0;
  INTERRUPTS=0;
  PCB_DEBUG=0;
  INSTRUCTIONS=0;
}

void Print_process_summary()
{struct PCBitem *i;
int run, ready, total;
int j;
int num_proc;
 float avg_run, avg_ready, avg_total;
 if (SUMMARY)
  {run = ready = 0;
   printf("\nFinal Summary of Process Statistics (time=%d)\n", Clock_Reg);
   printf("PID State Run Ready Total Name\n");
      if(SCHEDULER==3)
      {
	for(j=0;j<procid;j++)
	{
	total=arr[j]->run + arr[j]->ready;
	printf("%2d%5c%6d%5d%6d  %s\n", arr1[j], STATES[arr[j]->state], arr[j]->run,
	              arr[j]->ready, total, arr[j]->name);
          if ( arr[j]->proc >= 0 )
          {run += arr[j]->run;
           ready += arr[j]->ready;
          }
        }
	}
	else
	{
      for (i=PCB_head; i!=NULL; i=i->next) 
      {
       total = i->run + i->ready;
	printf("%2d%5c%6d%5d%6d  %s\n", i->proc, STATES[i->state], i->run,
              i->ready, total, i->name);
       if ( i->proc > 0 )
          {run += i->run;
           ready += i->ready;
          }
      }
	}
   total = run + ready;
   num_proc = number_of_processes-1;
   avg_run = run/num_proc;
   avg_ready = ready/num_proc;
   avg_total = total/num_proc;
   printf("\nAverage Run     Ready    Total times\n");
   printf("%11.2f%9.2f%9.2f\n",avg_run,avg_ready,avg_total);
  }
}


/* 
 * Print_transition prints a message when a process is moved from one
 * state to another.  It is called by all of the transition functions
 * in the os code.
 */
void Print_transition(char *transition, int pid)
{
 if (TRANSITIONS)
  {printf("Time=%d Pid=%d transition=%s.\n", Clock_Reg, pid, transition);
  }
}


/* 
 * These functions are used when the appropriate debug flag is set to 1.
 * They allow you to see the PCB data, the ready queue, the contents of 
 * primary memory.
 */

void Print_PCB_information()
{struct PCBitem  *i;
 if (PCB_DEBUG)
  {printf("The PCB Information\n");
   printf("pid state PC start run ready loc size name\n");
   for (i=PCB_head; i==PCB_tail; i=i->next)
      {if (i->state != ZOMBIE)
          {printf("%2d%5c%5d%4d%6d%4d%5d%5d  %s\n",
                   i->proc, STATES[i->state], i->PC, i->st_time,
                   i->run, i->ready, i->loc, i->size,
                   i->name);
          }
      }
  }
}


void Print_memory(int memory_size)
{int i;
 if (MEMORY)
  {printf("The Memory Contents:\n");
   printf(" 00 01 02 03 04 05 06 07 08 09 -- addresses");
   for (i=0; i<memory_size; i++)
      {if (i%10 == 0)
          {printf("\n");
          }
       printf("%3d", memory[i]);
      }
   printf("\n");
  }
}

/* 
 * Print_instruction shows the instruction, program counter and accumulator
 * for each executed instruction, except the NOOP instruction.  opcode is
 * the operation code and it is needed to activate the switch code correctly,
 * instruction is a text for the instruction.
 */

void Print_instruction(int opcode, char *instruction)
{if (INSTRUCTIONS)
 {switch (opcode)
  {case DONE:
   case INST:
    printf("Time=%d Pid=%d instruction=%s PC=%d\n",
            Clock_Reg, current_pid->proc, instruction, PC_Reg);
    break;
  }
 }
}


/* 
 * If the INTERRUPTS debug flag is set, then the interrupt list is written.
 */
void Print_interrupt_list()
{struct interrupt_event *x;
 if (INTERRUPTS)
  {printf("The Interrupt List ([time]pid): ");
   for (x = interrupt_list;x != NULL;x = x->forward)
      {printf("[%d]%d ", x->time, x->pid);
      }
   printf("\n");
  }
}


void Core_Debug(int sig)
{int i;
 debug_set();
 printf("Abort Operating System because signal %d was caught.\n", sig);
 printf("Time=%d Current Pid=%d\n", Clock_Reg, current_pid->proc);
 Print_memory(memory_size);
 Print_interrupt_list();
 Print_PCB_information();
 exit(0);
}
