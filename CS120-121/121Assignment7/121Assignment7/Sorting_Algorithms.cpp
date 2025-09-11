/*This is a comparison between two different sorting methods.

The first algorithm is a bubble sort that uses simple recursion in place
of a do-while loop.

The second is a selection sort that uses nested for-loops nested in
turn in a do-while loop.

In order to produce measureable results, an artifical slow-down
was implemented each time a swap is made, so more swaps meaps longer
completion time.  This slow-down is simply the print() function, and as
such, a sample output was provided.*/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

double recursiveBubble(int[], int);
double selection(int[], int);
void print(int[], int);

const int leng = 20;  //Length of the list.
const int girth = 1000;  //Maximum size of any one value on the list.

int main()
{
	srand(time(NULL));
	int stuff[leng], copyStuff[leng];
	double tickerBubble, tickerSelection;

	for (int i = 0; i < leng; i++)
	{
		stuff[i] = rand() % girth;
		copyStuff[i] = stuff[i];
	}

	print(stuff, leng);

	cout << "\nRunning bubble sorting: " << endl;
	tickerBubble = recursiveBubble(stuff, leng);
	cout << "\n\n" << "Running selection sorting: " << endl;
	tickerSelection = selection(copyStuff, leng);

	cout << "Bubble duration is: " << tickerBubble << endl;
	cout << "Selection duration is: " << tickerSelection << endl;

	//print(stuff, leng);
	//print(copyStuff, leng);
}

void print(int data[], int len)
{
	for (int j = 0; j < (len); j++)
	{
		cout << data[j] << " ";
	}
	cout << endl;
}

double recursiveBubble(int data[], int len)
{
	int temp1 = 0;

	time_t timer1, timer2;
	double duration = 0;

	bool sorted = true;

	time(&timer1);

	for (int i = 0; i < len - 1; i++)
	{
		if (data[i] > data[i + 1])
		{
			temp1 = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp1;
			sorted = false;
			print(data, len);
		}
	}
	if (sorted == false)
	{
		recursiveBubble(data, len);
	}

	time(&timer2);
	duration = difftime(timer2, timer1);

	return duration;
}

double selection(int data[], int len)
{	
	bool sorted = true;

	time_t timer1, timer2;
	double duration = 0;

	int temp = 0;	
	int indexer = 0;
	int smallest = data[0];  //This is the selection variable.

	time(&timer1);

	do {
		sorted = true;

		for (int j = 0; j < len; j++)
		{
			smallest = data[j];

			/*This first for loop finds the smallest value in the list,
			starting with the previously smallest value.  The index value
			is then updated to the new smallest value's location.*/
			for (int i = j + 1; i < len; i++)
			{
				if (smallest > data[i])
				{
					smallest = data[i];
					indexer = i;
				}
			}

			if (data[j] > data[indexer])
			{
				temp = data[j];
				data[j] = data[indexer];
				data[indexer] = temp;
				sorted = false;
				print(data, len);
			}
		}
	} while (sorted == false);

	time(&timer2);
	duration = difftime(timer2, timer1);

	return duration;
}
