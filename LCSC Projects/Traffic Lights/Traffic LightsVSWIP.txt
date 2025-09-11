//Todd Carter
//IETTI 221
//Traffic Light State Machine Simulator
//11-17-17

#include <stdio.h>
#include <windows.h> //This library seems needed to be able to use the Sleep() function.
#include <time.h>

int CStwo, CSone, CSzero, NStwo, NSone, NSzero, inCount, itCount;  //Global vars here probably not really necessary, but were added during the process and work well enough.  Could be integrated into int main with a little work.
int stZeLi, stFoLi; //State Zero Limit and State Four Limit.  Counters that will keep those states in check later.

int seedFile(void)  //This function creates the needed files if they weren't present, just to make sure it's there and iron out a possible error.  Why is it it's own function, you ask?  ...Why not?
{
	FILE*DFlipFlop; //This file will later provide state transitions similarly to a D Flip Flop.
	FILE*PrevInputs;  //This file stores the "location" of the "cars," so they don't have the potential to "vanish" with each state transition after "pulling up to the light."
	DFlipFlop = fopen("DFlipFlop.txt", "a");
	PrevInputs = fopen("PrevInputs.txt", "a");
	fclose(PrevInputs);
	fclose(DFlipFlop);
}

int inputOutput(int inAr0, int inAr1, int inAr2, int inAr3)  //This function displays where cars are currently waiting around the intersection.
{  //Each print statement is unique for the specific set of variables at that specific time, so there are a quite a few.
	if (inAr0 == 0 && inAr1 == 0 && inAr2 == 0 && inAr3 == 0)
	{
		if (stZeLi > 4)  //The counters come into play throughout this function, adjusting the output message depending on what count they've reached.
		{				 //Currently, the counters only allow 4 iterations of States 0 or 4 before forcing it to move on.
			printf("*-------------------------------------------------------------*\n"); //These print statements need to indicate that, so there are a lot of circumstances to consider.
			printf("*  There are no cars waiting at the intersection.             *\n"); //These only indicate where cars are WAITING, not driving. 
			printf("*                                                             *\n"); //As an example of what that means, this first if-else-if chain begins by checking if there are any cars DRIVING.
			printf("*                                                             *\n"); //As a result, these first two if-else-if checks are needed to see if there are any cars driving through, or if the intersection is totally empty.
			printf("*      No cars detected E/W.  Automatically moving on.        *\n"); 
			printf("*                                                             *\n");
		}else if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n"); //Incidentally, this and the previous are two of the rarest messages to be displayed.
			printf("*  There are no cars waiting at the intersection.             *\n"); //Both require there be no high inputs for 4 iterations while in State 0 or State 4.
			printf("*                                                             *\n"); //Since there are 4 inputs, each with a 1 in 6 chance of coming up per iteration, this is statistically highly improbable.
			printf("*                                                             *\n"); //I have seen it happen, so it's not impossible, at least.
			printf("*      No cars detected N/S.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stZeLi <= 4 && stFoLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are no cars waiting at the intersection.             *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 0 && inAr1 == 0 && inAr2 == 0 && inAr3 == 1)
	{
		if (stZeLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");			
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected E/W.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected N/S.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stZeLi <= 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 0 && inAr1 == 0 && inAr2 == 1 && inAr3 == 0)
	{
		if (stZeLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");			
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected E/W.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected N/S.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stZeLi <= 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 0 && inAr1 == 0 && inAr2 == 1 && inAr3 == 1)
	{
		if (stZeLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");			
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected E/W.  Automatically moving on.        *\n");
		}else if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected N/S.  Automatically moving on.        *\n");
		}else if (stZeLi <= 4 && stFoLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");
		printf("*    North/South turn lanes                                   *\n");
		printf("*    East/West turn lanes                                     *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 0 && inAr1 == 1 && inAr2 == 0 && inAr3 == 0)
	{
		if (stZeLi > 4)
		{				
			printf("*-------------------------------------------------------------*\n");
			printf("*  No cars detected.                                          *\n");    
			printf("*  Automatically moving on.                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stZeLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");    
		printf("*    North/South through-lanes                                *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 0 && inAr1 == 1 && inAr2 == 0 && inAr3 == 1)
	{
		if (stZeLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");			
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected E/W.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stZeLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");    
		printf("*    North/South through-lanes                                *\n"); 
		printf("*    North/South turn lanes                                   *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 0 && inAr1 == 1 && inAr2 == 1 && inAr3 == 0)
	{
		if (stZeLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected E/W.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stZeLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");   
		printf("*    North/South through-lanes                                *\n");
		printf("*    East/West turn lanes                                     *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 0 && inAr1 == 1 && inAr2 == 1 && inAr3 == 1)
	{
		if (stZeLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected E/W.  Automatically moving on.        *\n");
		}else if (stZeLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");    
		printf("*    North/South through-lanes                                *\n");
		printf("*    North/South turn lanes                                   *\n");
		printf("*    East/West turn lanes                                     *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 0 && inAr2 == 0 && inAr3 == 0)
	{
		if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  No cars detected.                                          *\n");
			printf("*  Automatically moving on.                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stFoLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");
		printf("*    East/West through-lanes                                  *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 0 && inAr2 == 0 && inAr3 == 1)
	{
		if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected N/S.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stFoLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");    
		printf("*    East/West through-lanes                                  *\n");   
		printf("*    North/South turn lanes                                   *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 0 && inAr2 == 1 && inAr3 == 0)
	{
		if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected N/S.  Automatically moving on.        *\n");
			printf("*                                                             *\n");
		}else if (stFoLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");   
		printf("*    East/West through-lanes                                  *\n");    
		printf("*    East/West turn lanes                                     *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 0 && inAr2 == 1 && inAr3 == 1)
	{
		if (stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*      No cars detected N/S.  Automatically moving on.        *\n");
		}else if (stFoLi <= 4)
		{
		printf("*-------------------------------------------------------------*\n");
		printf("*  There are cars waiting in:                                 *\n");    
		printf("*    East/West through-lanes                                  *\n");    
		printf("*    East/West turn lanes                                     *\n");    
		printf("*    North/South turn lanes                                   *\n");
		printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 1 && inAr2 == 0 && inAr3 == 0)
	{
		if (stFoLi > 4 && stZeLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West through-lanes                                  *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n"); 
			printf("*    North/South through-lanes                                *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  No cars detected.                                          *\n");
			printf("*  Automatically moving on.                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
		else if (stZeLi <= 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n"); 
			printf("*    East/West through-lanes                                  *\n");
			printf("*    North/South through-lanes                                *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 1 && inAr2 == 0 && inAr3 == 1)
	{
		if (stFoLi > 4 && stZeLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West through-lanes                                  *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n"); 
			printf("*    North/South through-lanes                                *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
		else if (stZeLi <= 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n"); 
			printf("*    East/West through-lanes                                  *\n");
			printf("*    North/South through-lanes                                *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 1 && inAr2 == 1 && inAr3 == 0)
	{		
		if (stFoLi > 4 && stZeLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West through-lanes                                  *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n"); 
			printf("*    North/South through-lanes                                *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
		else if (stZeLi <= 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n"); 
			printf("*    East/West through-lanes                                  *\n");
			printf("*    North/South through-lanes                                *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*                                                             *\n");
		}
	}
	else if (inAr0 == 1 && inAr1 == 1 && inAr2 == 1 && inAr3 == 1)
	{
		if (stFoLi > 4 && stZeLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West through-lanes                                  *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi <= 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n"); 
			printf("*    North/South through-lanes                                *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
		}else if (stZeLi > 4 && stFoLi > 4)
		{
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in:                                 *\n");
			printf("*    East/West turn lanes                                     *\n");
			printf("*    North/South turn lanes                                   *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
		else if (stZeLi <= 4 && stFoLi <= 4)
		{			
			printf("*-------------------------------------------------------------*\n");
			printf("*  There are cars waiting in all lanes.                       *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
			printf("*                                                             *\n");
		}
	}
}

int iterationCount(void) //This function is a line saver.  Not a lot in the outputs are repeating, but turning this into a function saved around eighty lines of code.
{  						//All this does is keep the outputs pretty, anyway.
	if (itCount > 0 && itCount <= 9)
	{
		printf("*  Iteration No. %i                                            *\n" , itCount);							
	}else if (itCount > 9 && itCount <= 99)
	{
		printf("*  Iteration No. %i                                           *\n" , itCount);
	}else if (itCount > 99 && itCount < 999)
	{
		printf("*  Iteration No. %i                                          *\n" , itCount);
	}else if (itCount > 999 && itCount < 9999)
	{
		printf("*  Iteration No. %i                                         *\n" , itCount);
	}else if (itCount > 9999 && itCount < 99999)
	{
		printf("*  Iteration No. %i                                        *\n" , itCount);
	}else if (itCount > 99999)
	{
		printf("*  Iteration No. Why did you even                               *\n");
	}
}

int main(void)
{
	int a, b, c, d, scnChk, inAr[4], preInAr[4]; //Some simple variables for general use, scanf checker, Input Array, and Previous Input Array
	char j;
	FILE*DFlipFlop;
	FILE*PrevInputs;
	srand(time(NULL));
	
	printf("You're gathering state transition data from traffic lights at an intersection.\nIt's a Spring day, a bit humid and overcast.  Might rain later.\nStill, you need to watch some lights, and you're on location.\nThe boss has really been on you after that whole 'train light' fiasco, so you feel you should try and make this good.\n");
	
	do
	{
		do
		{
			printf("\nHow many transitions do you want to observe?\n(There's no upper limit, but remember, each cycle takes nearly a second to display!)\n");
			scnChk = scanf("%i", &a);  //scnChk verifies that an integer was added.  A non-success from scanf will return a 0, while a single successful scan will return a 1.

			b = 1;
			stZeLi = 0;
			stFoLi = 0;

			if (scnChk == 1)  //Using scnChk first verifies that AT LEAST an integer was added.
			{
				if (a > 0) //Since 'a' had to be an integer, other possibilities are then eliminated with an if-else chain.
				{
					for (b = 1; b <= a; b++) //This loop controls how many iterations the user wants to see displayed.
					{
						seedFile();

						c = 0;

						DFlipFlop = fopen("DFlipFlop.txt", "r");  //This is where the state AFTER the D Flip Flop is brought back and added into the input combinatorial logic.
						fscanf(DFlipFlop, "%d %d %d", &CStwo, &CSone, &CSzero);
						fclose(DFlipFlop);

						for (c = 0; c <= 3; c++)  //This loop freshly randomizes the input array.
						{
							inAr[c] = rand() % 6; //In order to simulate relatively light traffic, a 1 in 6 chance of a car showing up at any particular sensor is used.
												
							if (inAr[c] <= 4)  //This if-else sets up a ratio out of the randomly chosen number to give 0 a better chance than 1.  This helps keep "traffic" more sparse.
							{
								inAr[c] = 0;  //This distribution pattern most clearly illustrates how difficult turning left is with this system at times.
							}				  //The limiter counter that is applied to States 0 and 4 helps keep traffic flowing even for the left turners.
							else if (inAr[c] > 4)
							{				  //40+ iterations gave okay results with these settings, though seeing all the transition scenarios be simulated can take a while.
								inAr[c] = 1;  //A higher ratio would increase transition rate, but simultaneously make scenarios where traffic has emptied out never come up.
							}				  //Finding a good balance took some tinkering, and still isn't perfect, but it looks "realistic" this way, in my opinion.
						}

						PrevInputs = fopen("PrevInputs.txt", "r");  //This is where previous inputs are pulled from their save file.
						fscanf(PrevInputs, "%i %i %i %i", &preInAr[0], &preInAr[1], &preInAr[2], &preInAr[3]);
						fclose(PrevInputs);  //This is done for the sake of "remembering" where the cars were previously, in case their light hasn't turned green yet.

						for (d = 0; d <= 3; d++)  //In this loop, the previous inputs are compared against the new inputs.  
						{						  //This means when a car "pulls up" when the light is red, it won't just "vanish" on the next transition.
							if (inAr[d] == 1 || preInAr[d] == 1)
							{
								inAr[d] = 1;
							}
						}

						if (CStwo == 0 && CSone == 0 && CSzero == 0) //This if-else chain compares the current state with the relevant inputs.
						{  					  //This replicates the input combinatorial logic of the state machine, with some minor improvements.							
							if (inAr[1] == 0) //Each state is only truly dictated by a single input, so to create a "transition," only those inputs are relevant.
							{								
								NStwo = 0;
								NSone = 0;
								NSzero = 0;								
								stZeLi = stZeLi + 1; //This is a counter segment.  It adjusts the global variable each time State 0 (E/W thru green) comes up.
								if (stZeLi > 4) //Here the limiter counter is used to advance the state early if necessary.
								{
									NStwo = 0;
									NSone = 0;
									NSzero = 1;
								}
							}
							else if (inAr[1] == 1)
							{
								NStwo = 0;
								NSone = 0;
								NSzero = 1;
							}
							inAr[0] = 0;  //Certain "lanes" are allowed to go when their light turns green or yellow, therefore the sensor input reduces to zero.
							itCount = itCount + 1; //This and other similar lines increment the global Iteration Count variable for later use.
						}				  
						else if (CStwo == 0 && CSone == 0 && CSzero == 1)
						{						
							if (inAr[3] == 0)
							{
								NStwo = 1;
								NSone = 0;
								NSzero = 0;
							}
							else if (inAr[3] == 1)
							{
								NStwo = 0;
								NSone = 1;
								NSzero = 0;
							}
							inAr[0] = 0;						
							itCount = itCount + 1;
						}
						else if (CStwo == 0 && CSone == 1 && CSzero == 0)
						{
							if (inAr[3] == 0)
							{
								NStwo = 0;
								NSone = 1;
								NSzero = 1;
							}
							else if (inAr[3] == 1)
							{
								NStwo = 0;
								NSone = 1;
								NSzero = 0;
							}
							inAr[3] = 0;
							itCount = itCount + 1;
						}
						else if (CStwo == 0 && CSone == 1 && CSzero == 1)
						{
							NStwo = 1; //This segment represents State 3, which can only transition to State 4.
							NSone = 0;
							NSzero = 0;
							
							inAr[3] = 0;
							itCount = itCount + 1;
						}
						else if (CStwo == 1 && CSone == 0 && CSzero == 0)
						{
							if (inAr[0] == 0)
							{
								NStwo = 1;
								NSone = 0;
								NSzero = 0;
								stFoLi = stFoLi + 1;  //This is the limiter segment for State 4 (N/S thru green)
								if (stFoLi > 4)
								{									
									NStwo = 1;
									NSone = 0;
									NSzero = 1;
								}
							}
							else if (inAr[0] == 1)
							{
								NStwo = 1;
								NSone = 0;
								NSzero = 1;
							}
							inAr[1] = 0;
							itCount = itCount + 1;
						}
						else if (CStwo == 1 && CSone == 0 && CSzero == 1)
						{
							if (inAr[2] == 0)
							{
								NStwo = 0;
								NSone = 0;
								NSzero = 0;
							}
							else if (inAr[2] == 1)
							{
								NStwo = 1;
								NSone = 1;
								NSzero = 0;
							}							
							inAr[1] = 0;
							itCount = itCount + 1;
						}
						else if (CStwo == 1 && CSone == 1 && CSzero == 0)
						{
							if (inAr[2] == 0)
							{
								NStwo = 1;
								NSone = 1;
								NSzero = 1;
							}
							else if (inAr[2] == 1)
							{
								NStwo = 1;
								NSone = 1;
								NSzero = 0;
							}
							inAr[2] = 0;
							itCount = itCount + 1;
						}
						else if (CStwo == 1 && CSone == 1 && CSzero == 1)
						{
							NSone = 0;
							NStwo = 0;
							NSzero = 0;
							
							inAr[2] = 0;
							itCount = itCount + 1;
						}	

						DFlipFlop = fopen("DFlipFlop.txt", "w");  //The resulting state of the combinatorial logic is logged here, where it will go to serve as the current state on the next iteration.
						fprintf(DFlipFlop, "%i %i %i", NStwo, NSone, NSzero);
						fclose(DFlipFlop);

						if (CStwo == 0 && CSone == 0 && CSzero == 0) //This if-else chain guides what lights are currently green, based on the current state.
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*    ( R )         >>( R )<<       >>( R )<<       >>( R )<<  *\n");
							printf("*    ( Y )           ( Y )           ( Y )           ( Y )    *\n");
							printf("*  >>( G )<<         ( G )           ( G )           ( G )    *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");							
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stZeLi > 4)
							{
								stZeLi = 0; //This resets the counter once it's needed.
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");							
							Sleep(750); //Adds a delay, mostly just for appearances on the monitor; it looked strange having each happen instantly.  A slight pause makes it flow more naturally.
						} //Since it is purely for aesthetics and might slow down testing, it can be lowered or removed without affecting the program functionality.
						else if (CStwo == 0 && CSone == 0 && CSzero == 1) //Technically, the delay should be about 15 seconds for a "realistic" traffic-light-watching experience.
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*    ( R )         >>( R )<<       >>( R )<<       >>( R )<<  *\n");
							printf("*  >>( Y )<<         ( Y )           ( Y )           ( Y )    *\n");
							printf("*    ( G )           ( G )           ( G )           ( G )    *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");							
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stZeLi <= 4 || stFoLi <= 4)
							{
								stFoLi = 0; //This and the other similar segments zero out the counters when their state is not active.
								stZeLi = 0;
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");
							Sleep(750);
						}
						else if (CStwo == 0 && CSone == 1 && CSzero == 0)
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*  >>( R )<<       >>( R )<<       >>( R )<<         ( R )    *\n");
							printf("*    ( Y )           ( Y )           ( Y )           ( Y )    *\n");
							printf("*    ( G )           ( G )           ( G )         >>( G )<<  *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");							
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stZeLi <= 4 || stFoLi <= 4)
							{
								stFoLi = 0;
								stZeLi = 0;
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");							
							Sleep(750);
						}
						else if (CStwo == 0 && CSone == 1 && CSzero == 1)
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*  >>( R )<<       >>( R )<<       >>( R )<<         ( R )    *\n");
							printf("*    ( Y )           ( Y )           ( Y )         >>( Y )<<  *\n");
							printf("*    ( G )           ( G )           ( G )           ( G )    *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");							
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stZeLi <= 4 || stFoLi <= 4)
							{
								stFoLi = 0;
								stZeLi = 0;
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");
							Sleep(750);
						}
						else if (CStwo == 1 && CSone == 0 && CSzero == 0)
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*  >>( R )<<       >>( R )<<         ( R )         >>( R )<<  *\n");
							printf("*    ( Y )           ( Y )           ( Y )           ( Y )    *\n");
							printf("*    ( G )           ( G )         >>( G )<<         ( G )    *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");							
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stFoLi > 4)
							{
								stFoLi = 0;
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");							
							Sleep(750);
						}
						else if (CStwo == 1 && CSone == 0 && CSzero == 1)
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*  >>( R )<<       >>( R )<<         ( R )         >>( R )<<  *\n");
							printf("*    ( Y )           ( Y )         >>( Y )<<         ( Y )    *\n");
							printf("*    ( G )           ( G )           ( G )           ( G )    *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");							
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stZeLi <= 4 || stFoLi <= 4)
							{
								stFoLi = 0;
								stZeLi = 0;
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");
							Sleep(750);
						}
						else if (CStwo == 1 && CSone == 1 && CSzero == 0)
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*  >>( R )<<         ( R )         >>( R )<<       >>( R )<<  *\n");
							printf("*    ( Y )           ( Y )           ( Y )           ( Y )    *\n");
							printf("*    ( G )         >>( G )<<         ( G )           ( G )    *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");							
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stZeLi <= 4 || stFoLi <= 4)
							{
								stFoLi = 0;
								stZeLi = 0;
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");							
							Sleep(750);
						}
						else if (CStwo == 1 && CSone == 1 && CSzero == 1)
						{
							printf("\n\n***************************************************************\n");
							iterationCount();
							printf("*  The lights currently are:                                  *\n");
							printf("*                                                             *\n");
							printf("****East/West******East/West******North/South*****North/South**\n");
							printf("**Through-Lanes****Turn Lanes****Through-Lanes****Turn Lanes***\n");
							printf("*  >>( R )<<         ( R )         >>( R )<<       >>( R )<<  *\n");
							printf("*    ( Y )         >>( Y )<<         ( Y )           ( Y )    *\n");
							printf("*    ( G )           ( G )           ( G )           ( G )    *\n");
							printf("*                                                             *\n");
							printf("*                                                             *\n");						
							inputOutput(inAr[0], inAr[1], inAr[2], inAr[3]);
							if (stZeLi <= 4 || stFoLi <= 4)
							{
								stFoLi = 0;
								stZeLi = 0;
							}
							printf("*                                                             *\n");
							printf("***************************************************************\n");
							Sleep(750);
						}						
						PrevInputs = fopen("PrevInputs.txt", "w");  //This is where the current inputs are logged as previous inputs to be used later.
						fprintf(PrevInputs, "%i %i %i %i" , inAr[0], inAr[1], inAr[2], inAr[3]);
						fclose(PrevInputs);
					}
					inCount = inCount + a; //This increments the global Input Count variable, adding the newest
				}
				else if (a < 0)
				{
					printf("\nImpossible amount.\n");
				}
				else if (a == 0)
				{
					printf("\nSlacking on the job?  Tsk, tsk.\n\n"); //The best programs are snarky.
				}
			}
			else if (scnChk != 1)
			{
				printf("\nImpossible amount.\n");
				getchar();
			}
			
			if (itCount == 0)
			{
				printf("\nI mean, you could just lie about it and be a real credit to the team.\nYou only have the respect of your loved ones, your peers, and yourself to lose.\nOh, and maybe your job.\n");
			}else if (itCount > 0 && itCount <= 40)
			{
				printf("\n'I should probably watch some more,' you think to yourself.\n'Might look good on the report, and it's not very difficult.'\nEven as you flip to a new page on your clipboard, however, a raindrop lands and smudges some ink.\nDecisions, decisions.\n");
			}else if (itCount > 40 && itCount <= 99)
			{
				printf("\nThat's probably enough, right?\nThat's like, dozens, already, and you really aren't too sure if that was thunder or a truck rumbling past.\nThen again, the litigation from the train company hasn't fully cleared yet...\n");
			}else if (itCount > 99 && itCount <= 250)
			{
				printf("\n'Yeah, that looks good,' you think to yourself approvingly.\nYou tuck your pen back in the clipboard with the satisfaction of a job well done.\nLucky you stayed out, too, the sun's shining and the day turned out just beautiful.\n");
			}else if (itCount > 250)
			{
				system("cls");
				printf("\nOh god, you stayed out too long in the nice weather, and the rain came back in force.\nYour notes are a total wash.  You'll have to start over, and predictably, the Spring shower flits away.\nRegardless, you've already gone way over your time alotted for this thing, and now have nothing to show.\nThe boss is not going to be happy...\n");
				itCount = 0;
				
			}
			j = 'g';			
			printf("\nContinue gathering data? Y/N\n");			
			scanf(" %c", &j);
		} while (scnChk != 1); //If it didn't read an integer earlier, this is where it loops back.
	} while (j == 'y' || j == 'Y');
		if (inCount == 0)
		{
			printf("\nFine, then.  Hopefully your boss isn't surprised by now, at least.\n\n\n");
		}else if (inCount > 0 && inCount <= 40)
		{
			printf("\nEh, the bits you saw were working.  You can just tell the boss you got rained out.\nHe won't care, you got some of what he asked done, at least.\n\n\n");
		}else if (inCount > 40 && inCount <= 99)
		{
			printf("\nThat's not bad.  May have gotten a good example or two in there.\nThat definitely sounded like thunder that time.\nTime to beat a hasty retreat.\n\n\n");
		}else if (inCount > 99 && inCount <= 250)
		{
			printf("\nYou enjoy a leisurely walk in the splendid weather.\nA Spring shower sprang suddenly up behind you, and you're able to easily avoid it.\nThe day really shaped up after all.\n\n\n");
		}else if (inCount > 250)
		{
			printf("\nWell, hopefully the boss will understand.\nAgain.\n\n\n");
			inCount = 0;
			itCount = 0;
		}
	return (0);
}
