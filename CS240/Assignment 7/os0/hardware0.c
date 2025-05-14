/* The hardware simulation code for project number zero in CS341

   functions called by the operating system are:
      hardware()
      start_io(int type, int process)

   functions that this code calls in the operating system are:
      exceptions(int type)
      interrupts(int process)
*/

#include   <stdio.h>
#include   "hardware0.h"

/* This is the interrupt event queue definition.
*/
struct  interrupt_event *interrupt_list;

/* These are the central registers of the virtual computer:
   Clock_Reg is the CPU clock and is updated after each instruction is
      executed.
   PC_Reg is the Program Counter register and is updated after the 
      successful execution of each instruction.  Whenever a new process
      is started by the operating system, the operating system must
      initialize this to its correct value.
*/
int  Clock_Reg = 0;
int  PC_Reg;

/* running is the variable used to indicate that the hardware has something
   to do.  It is set to 0 within the function start_io(OFF,OFF) when all
   processes are complete.
*/
int  running = 1;

/* Declares the array used to simulate the RAM (primary memory) used
   by the hardware simulation.
*/
int  memory[MEMORY_SIZE];

/* Executes the machine level instructions within the hardware simulation.
*/
void execute_instructions()
{int opcode;
   opcode = memory[PC_Reg];
   switch (opcode)
      {case DONE:   Print_instruction(opcode, "HALT");
                    exceptions(HALT);
                    break;
       case INST:   Print_instruction(opcode, "INST");
                    PC_Reg++;
                    break;
       case NOOP:   exceptions(NOOPEX);
                    break;
       default:     exceptions(ILLEGAL);
                    break;
      }
}

/* Simulates the interrupt section of the hardware simulation.  Interrupts
   are represented as a list of future interrupt events.  Each event
   contains data about the associated process and the time that the event
   will occur.
*/
void interrupt_check()
{struct interrupt_event *i;
   i = interrupt_list;
   while (i != NULL)
      {/* look for an event that might be happening at this time. */
       if ( i->time == Clock_Reg )
          {interrupts(i->pid);
          }
       i = i->forward;
      }
}

/* This is the heart of the hardware simulation.  The simulation runs
   until running is set to 0 (which happens when start_io(OFF,OFF) is
   called) or when time reaches 10000.
*/
void hardware()
{
   while (running && Clock_Reg<10000)
      {Clock_Reg++;
       execute_instructions();
       interrupt_check();
}
}


/* This procedure is called by operating system to start a specific I/O
   operation.  At this time the only I/O operations are OFF and TIMER.
*/
void start_io(int type, int process)
{struct interrupt_event *event;
   switch (type)
      {case OFF:    /* OFF switch, all processing complete.  Nullify all
                       future interrupts since the simulation is complete
                       and set running to 0 to signal the end of the
                       hardware simulation */
                    interrupt_list = NULL;
                    running = 0;
                    return;
       case TIMER:  /* start interval timer by creating a timer event. */
                    if (interrupt_list == NULL)
                       {/* this is the first time the interval timer is being
                           used, so create a timer event. */
                        event = (struct interrupt_event *)
                                malloc(sizeof(struct interrupt_event));
                        event->time = Clock_Reg + TIMESLICE;
                        event->pid = process;
                        event->forward = NULL;
                        interrupt_list = event;
                       }
                    else
                       {/* a timer event should already exist at the front of
                           the interrupt list, so reset it for the correct
                           interval. */
                        event = interrupt_list;
                        event->time = Clock_Reg + TIMESLICE;
                        event->pid = process;
                       }
                    break;
      }
   Print_interrupt_list();
}
