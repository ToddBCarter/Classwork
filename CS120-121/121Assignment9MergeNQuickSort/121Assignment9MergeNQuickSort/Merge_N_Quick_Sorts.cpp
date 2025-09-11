/*This code consists of two different sorting algorithms, a merge sort and a quick sort.
After sufficient testing which is documented in the text file 121assignment9output2 attached
to the assignment, it was clear that merge sort was consistently faster with a list of
larger sizes.  As can be seen in the other file 121assignment9output1, the two algorithms
are very similar in speed on smaller lists.

This code is for the final product which tested the 100k list.  Some remnants of the
code that produced 121assignment9output1 exist as comments.*/

#include<iostream>
#include<ctime>
#include<chrono>
using namespace std;

const int len = 10;
const int longlen = 100000;

void print(int[], int);
void mergeSort(int[], int, int);
void inplacequicksort(int[], int, int);

int main()
{
	srand(777);

	int stuff[longlen], stuff2[longlen];

	for (int i = 0; i < longlen; i++)
	{
		stuff[i] = rand() % 99;
		stuff2[i] = stuff[i];
	}

	//-------------------------------------------------------------------------------------//

	cout << "Testing merge sort with a list of 100,000 values...\n" << endl;
	//print(stuff, len);

	cout << endl;

	auto start = chrono::steady_clock::now();

	mergeSort(stuff, 0, longlen - 1);

	auto end = chrono::steady_clock::now();

	cout << endl;

	//print(stuff, len);

	cout << "\nMerge Sort took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns to complete." << endl;

	cout << "\n\n\n--------------------------------------\n\n\n" << endl;


	//-------------------------------------------------------------------------------------//

	cout << "Testing quick sort with a list of 100,000 values...\n" << endl;

	//print(stuff2, len);

	cout << endl;

	start = chrono::steady_clock::now();

	inplacequicksort(stuff2, 0, longlen - 1);

	end = chrono::steady_clock::now();

	cout << endl;

	//print(stuff2, len);

	cout << "\Quick Sort took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns to complete." << endl;

	cout << endl;

	cout << "\n\n\n--------------------------------------\n\n\n" << endl;


}

void print(int data[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << data[i] << endl;
	}
}

void mergeSort(int data[], int low, int high)
{
	/*Calling new variables to be used as trackers for sorting.*/
	int z = low;
	int locA = 0;
	int locB = 0;


	/*Immediately checking if the recursion has reached its conclusion or not.*/
	if (low >= high)
	{
		return;
	}

	int mid = (high + low) / 2;  //Splitting the size of the array in half.

	mergeSort(data, low, mid);  //Recursively calling the function using the mid point.
	mergeSort(data, (mid + 1), high); //The +1 prevents overlap while the second half is called.

	/*This seemed to be the best location for the print function to show what is happening
	to the original data[] array.*/
	//cout << endl;
	//print(data,len);
	//cout << endl;


	  /*Now that the recursions are collapsing, new variables are used.
	  This will create temporary arrays that will then merge the data back into
	  the original array in the correct order.*/

	int sizeA = mid - low + 1;  //This variable establishes the size of half the array.
	int sizeB = high - mid;  //The other half of the array.

	int sideA[sizeA];  //These are the temporary half-size arrays.
	int sideB[sizeB];

	/*For loops that copy the original array into the temporary arrays.*/
	for (int i = 0; i < sizeA; i++)
	{
		sideA[i] = data[i + low];
		/*low must be added in order to compensate for the secondary arrays.
		Since each recursion breaks the list in half, the second half must
		take data from proportionately further along the original array.*/
	}
	for (int i = 0; i < sizeB; i++)
	{
		sideB[i] = data[i + mid + 1];
		//As with low, mid+1 must be added as it had been in the recursion.
	}

	/*locA and locB are used to independetly track locations in the temporary
	arrays. The while loop steps them along so the if statement can
	make the comparisons.  Each comparison puts the smaller variables
	back into the original array first and then increments the pertaining
	variable.*/
	while (locA < sizeA && locB < sizeB)
	{
		if (sideA[locA] <= sideB[locB]) //Doing the core comparison.
		{
			data[z] = sideA[locA];
			locA++;
		}
		else
		{
			data[z] = sideB[locB];
			locB++;
		}
		z++;
	}

	/*These last while loops check for any remaining elements and
	puts them into data, as they should be sorted.*/
	while (locA < sizeA)
	{
		data[z] = sideA[locA];
		locA++;
		z++;
	}

	while (locB < sizeB)
	{
		data[z] = sideB[locB];
		locB++;
		z++;
	}
}


void inplacequicksort(int data[], int low, int high)
{
	//Immediately check if the recursion has ended.
	if (high - low < 1)
	{
		return;
	}

	//Assign the new top and pivot points.
	int top = high;
	int pivot = low;

	/*Using a while loop to measure the pivot against the top array member.*/
	while (pivot < top)
	{
		/*Provided that the top value is greater or equal to the pivot,
		the tracker for top can be advanced to allow the next value to
		be checked.*/
		if (data[top] >= data[pivot])
		{
			top--;
		}
		else
		{
			/*This if statement will sort from the pivot side as well.  By checking
			the pivot against the next value in line, this will sort the pivot forward.*/
			if (data[pivot] >= data[pivot + 1])
			{
				int temp = data[pivot];
				data[pivot] = data[pivot + 1];
				data[pivot + 1] = temp;

				pivot++;
			}
			else
			{
				/*Since the pivot is being sorted with the value one element ahead, then
				if the other tests have failed, this will swap the value that has been
				determined to be smaller with the top value.*/
				int temp = data[pivot + 1];
				data[pivot + 1] = data[top];
				data[top] = temp;
			}
		}
	}

	/*Finally. call recursions on the top half and bottom half as dictated by the pivot.
	These will continue on until tripping the check return at the beginning.*/
	inplacequicksort(data, low, pivot);
	inplacequicksort(data, pivot + 1, high);

	/*This also seemed to be the best location for the print function to show what is happening
	  to the original data[] array.*/
	  //cout << endl;
	  //print(data,len);
	  //cout << endl;

}

