/*   CS341  -- Operating System version 98.0       */

/* 
 * These are the routines that the constitute the operating system.
 */

#include "os0main.h"
#include "hardware0.h"
#include <stdio.h>

/* PCB  queue definition */
struct PCBitem *PCB_head=NULL;
struct PCBitem *PCB_tail=NULL;
struct PCBitem *PCB_curr,*PCB_print;

/*
 * central variables for the virtual computer, these are used by
 * the operating system to keep track of processes
 */
struct PCBitem *current_pid;
struct PCBitem *PCB;
int  live_processes = 0;
int  number_of_processes;
int  memory_size;
int procid;
//--- Used in printing round robin scheduling algorithm
struct PCBitem *arr[MAX];
int arr1[MAX];

/* 
 * Exception handler, HALT, NOOPEX, and ILLEGAL; outputs a message
 *  and then disposes of the process and dispatches another
 */

void exceptions(int type)
{
   switch (type)
      {case HALT:    Kill_process();
		     Dispatch_process();
                     break;
       case NOOPEX:  if (current_pid == NULL)
                        {Timeout_process();
                         Dispatch_process();
                         break;
                        }
                     /* the NOOP instruction can only be used by the NULL
                        process, so when the if part is untrue we have an
                        illegal instruction, so we continue */
       case ILLEGAL: printf("ERROR: Pid=%d attempted the illegal ",
                            current_pid->proc);
                     printf("instruction %d\n at location %d at time %d.\n", 
                            memory[PC_Reg], PC_Reg, Clock_Reg);
                     Kill_process();
                     Dispatch_process();
                     break;}
}

/* 
 * Interrupt handler.
 */
void interrupts(int process)
{
 Timeout_process();
 Dispatch_process();
}

void Timeout_process()
{  current_pid->PC = PC_Reg - current_pid->loc;
   Print_transition("Timeout", current_pid->proc);
   current_pid->run += Clock_Reg-current_pid->st_time;
   current_pid->state = READY;
   current_pid->st_time = Clock_Reg;
   if((current_pid->proc)!= 0)
   {
	if(PCB_head==NULL)
	{
	PCB_head=PCB_curr;
	}
        PCB_tail->next=PCB_curr;
	PCB_tail->next->next=NULL;
        PCB_tail=PCB_curr;
  }
}

void Dispatch_process()
{
  Print_PCB_information();
  if (live_processes == 0)
     { current_pid->ready += Clock_Reg-current_pid->st_time;
       current_pid->state = TERMINATED;
       current_pid->st_time = Clock_Reg;
	if(SCHEDULER==3)
	{
	current_pid->proc=0;
       }
	start_io(OFF,OFF);
       return;
      }
   current_pid = process_scheduler();
   PC_Reg = current_pid->PC + current_pid->loc;
   Print_transition("Dispatch", current_pid->proc);
   current_pid->ready += Clock_Reg-current_pid->st_time;
   current_pid->state = RUNNING;
   if (SCHEDULER==3)
      {start_io(TIMER, current_pid->proc);
      }
   current_pid->st_time = Clock_Reg;
}

struct PCBitem* process_scheduler()
{
struct PCBitem *pid;
struct PCBitem *i, *lowest, *j;
int losize;
   switch (SCHEDULER)
   {case FCFS:     if(PCB_curr->state==READY)
		   {
                   pid=PCB_curr;
		   }
		   PCB_curr = PCB_curr->next;
                   break;


       case SJF:   losize=MEMORY_SIZE;
                   for (i=PCB_head;i!= NULL; i=i->next)
                    {if(i->state == READY)
                          {if (i->size < losize)
                              {losize = i->size;
                               j = i;
                              }
                          }
                      }
                   if (losize == MEMORY_SIZE)
                      {pid = 0;
                      }
                   else
                      {pid = j;
                      }
                   break;

       case RR:    if (PCB_head == NULL)
                      {pid = NULL;
                      }
                   else
                      {
		        pid = PCB_head;
		        PCB_curr=pid;
			PCB_head = PCB_head->next;
			}
                   break;
      }
   return pid;
}  //returns the address of the Process Control Block

void Kill_process()
{
   current_pid->PC = PC_Reg - current_pid->loc;
   current_pid->run += Clock_Reg-current_pid->st_time;
   Print_transition("Kill", current_pid->proc);
   current_pid->state = TERMINATED;
   current_pid->st_time = Clock_Reg;
   live_processes--;
}


/* 
 * Create a new process by initializing the entire PCB and loading
 * the code for this process into memory.
 */

void Create_process(int pid, char *name, int *addr)
{FILE *pfile;
 int   inst;
    live_processes++;
    PCB=(struct PCBitem *)malloc(sizeof(struct PCBitem));
    strcpy(PCB->name, name);
    PCB->state = READY;
    PCB->PC = 0;
    PCB->loc = *addr;
    PCB->st_time = Clock_Reg;
    PCB->run = 0;
    PCB->ready = 0;
    PCB->size = 0;
    PCB->next=NULL;
    PCB->proc=++procid; //used to store Process id

    if ((pfile = fopen(name,"r")) == NULL)
       {printf("ERROR: Unable to open the process file %s\n", name);
        exit(1);
       }
    while (fscanf(pfile, "%d", &inst) != EOF)
       {memory[(*addr)++] = inst;
        PCB->size++;
       }
    fclose(pfile);
    if(PCB_head==NULL)
	{
	PCB_head=PCB;
	PCB_print=PCB;
	PCB_tail=PCB;
	PCB_curr=PCB_head;
	}
    else
	{
	PCB_tail->next=PCB;
        }
	PCB_tail=PCB;
	if(SCHEDULER==3)//Used by Round Robin Scheduling algorithm
	{
	arr[procid-1]=PCB; //Stores PCB address
	arr1[procid-1]=PCB->proc;// Stores process id
	}
Print_transition("Create", PCB->proc);
}

