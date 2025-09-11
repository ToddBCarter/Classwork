const int rows = 15;
const int columns = 40;

class life
{
private:
	int board[rows + 2][columns + 2]; //This is the primary array.
	int adjC[rows + 2][columns + 2];  //This array is used as temporary storage for the number of adjacent cells.
	int iteration;  //Turn counter, mostly for fun.
public:
	life();
	void checkDoA(int x, int y);  //Check if a cell is dead or alive.  This is where Conway's rules are located.
	void checkAdj(int x, int y);  //Makes a count of adjacent living cells.
	void print();
	void setDoA(int, int);
	void run(int);
	void randomizer();
};

life::life()
{
	for (int i = 0; i < rows + 2; i++)
	{
		for (int j = 0; j < columns + 2; j++)
		{
			board[i][j] = 0;
		}
	}
	for (int i = 0; i < rows + 2; i++)
	{
		for (int j = 0; j < columns + 2; j++)
		{
			adjC[i][j] = 0;
		}
	}
	iteration = 0;
}

void life::run(int iti)
{
	for (int run = 0; run < iti; run++)
	{
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= columns; j++)
			{
				checkAdj(i, j);
			}
		}
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= columns; j++)
			{
				checkDoA(i, j);
			}
		}
		iteration++;
		print();
	}
}

void life::checkDoA(int x, int y)
{
	if (board[x][y] == 0)
	{
		if (adjC[x][y] == 3)
		{
			board[x][y] = 1;
		}
	}
	if ((adjC[x][y] == 2 && board[x][y] == 1) || (adjC[x][y] == 3 && board[x][y] == 1))
	{
		board[x][y] = 1;
	}
	if (adjC[x][y] < 2)
	{
		board[x][y] = 0;
	}
	if (adjC[x][y] > 3)
	{
		board[x][y] = 0;
	}

	adjC[x][y] = 0;
}

void life::checkAdj(int x, int y)
{
	for (int i = 0; i < rows + 2; i++)
	{
		for (int j = 0; j < columns + 2; j++)
		{
			if (i == 0 || j == 0 || i == 16 || j == 41)
			{
				board[i][j] = 0;
			}
			else if (i == 16 || j == 41)
			{
				board[i][j] = 0;
			}
		}
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			adjC[x][y] += board[x + i][y + j];
		}
	}
	adjC[x][y] -= board[x][y];
	
	//cout << "adjCount for " << x << " " << y << " is: " << adjC[x][y] << endl;
	//cout << "DoA for " << x << " " << y << " is: " << board[x][y] << endl;
}

void life::setDoA(int x, int y)
{
	if (x > -1 && y > -1)
	{
		if (board[x][y] == 0)
		{
			board[x][y] = 1;
		}
		else
		{
			board[x][y] = 0;
		}
	}
	//cout << "DoA right after set for " << x << " " << y << "is: " << board[x][y] << endl;
}

void life::print()
{
	//system("cls");	//Clear the screen for fun.  Not used for output.
	cout << "\nTurns passed: " << iteration << endl;
	for (int i = 1; i <= rows; i++)
	{
		if (i <= 6)
		{
			cout << (rows - i) + 1 << "|";
		}
		else 
		{
			cout << " " << (rows - i) + 1 << "|";
		}
		for (int j = 1; j <= columns; j++)
		{
			if (board[i][j] == 1)
			{
				cout << " X ";
			}
			else
			{
				cout << " . ";
			}

		}
		cout << "|";
		cout << endl;
	}

	cout << "   ";
	for (int i = 1; i <= columns; i++)
	{
		if (i > 9)
		{
			cout << i << " ";
		}
		else
		{
			cout << " " << i << " ";			
		}

	}
	cout << " " << endl;

	/*A brief pause here keeps things sane while testing.*/
	Sleep(300);
}

void life::randomizer()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{			
			int r = rand() % 15 + 1;
			int s = rand() % 40 + 1;
			board[r][s] = rand() % 2;
		}
	}
}