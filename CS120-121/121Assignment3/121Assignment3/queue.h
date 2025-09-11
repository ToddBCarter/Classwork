/*Assignment 3
CS 121-01
2-3-2022*/

/*This queue class uses pointers to keep track of the head and the
tail of the list.  These pointers are constrained by the constant
variable len (length), which creates a pseudo-list within the
array.  Very basic pointer arithmetic is used to advance the
queue up and down the list, wrapping around the end of the array
to overwrite old data.  Integers were used for the sake of
simplicity.*/

/*Enumerated type.  eC standing for error code.*/
enum eC { success, fail, overflow, underflow };

/*Typedef addition of quTyp, standing for queue type.*/
typedef int quTyp;

const int len = 5;

class queue
{
private:
	/*The list array being much longer than the max
	length is important.  This means the pointers, and
	thus the queue, will never overlap.*/
	int list[len * 2];
	int* head, *tail, count;
public:
	queue();
	bool empty();
	eC push(quTyp);
	eC pop();
	eC front(quTyp);
	void print();
};

queue::queue()
{
	head = &list[0];
	tail = &list[0];
	count = 0;
}

bool queue::empty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

eC queue::push(quTyp number)
{
	
	if (count >= len)
	{
		return overflow;
	}
	else {

		*tail = number;
		if (tail == &list[(len * 2) - 1])
		{
			tail = &list[0];
		}
		else
		{
			tail++;
		}
		count++;
		return success;
	}
}

eC queue::pop()
{
	if (count <= 0)
	{
		return underflow;
	}
	else
	{
		*head = -1;
		if (head >= &list[(len * 2) - 1])
		{
			head = &list[0];
		}
		else
		{
			head++;
		}
		count--;
		return success;
	}

}

eC queue::front(quTyp number)
{
	if (count > 0)
	{
		*head = number;
		return success;
	}
	else
	{
		return overflow;
	}
}

/*The print statement uses temporary pointers to create a temporary queue,
then increments through that temporary list.*/
void queue::print()
{
	int* tHead = head, *tTail = tail;

	cout << "\n";
	for (int i = 0; i <= count; i++)
	{
		if (tHead != tTail)
		{
			cout << "This is element number " << i << ": " << *tHead << endl;
			tHead++;
			if (tHead > &list[(len * 2) - 1])
			{
				tHead = &list[0];
			}
		}


	}
	cout << "\n";
}