/*This is a gopher game that has been built as an homage to a specific
minigame from a classic video game on Gamecube, Legend of Zelda:
Wind Waker.  This game only takes the theme, and otherwise follows
the gopher game definition, more or less.  The concept is that you are
hunting squids on the high seas using a cannon, and you have to figure
out where the squids are in order to hit them as you go.  If you miss,
you'll hit a child, which loses you the game.

The program uses a 2D class array and an array of pointers to pass data
around as needed.  This was a terrible decision on my part, and as a
result, this entire thing is a huge mess, but it works if left alone
just as it is.*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class squid_square
{
private:
	//int DoA;
public:
	squid_square();

	/*These variables can be read as squid, which indicates if the object has a squid or not,
	 Adjacent Flag which is used to spread out the collateral damage, Adjacent Squids, which 
	 keeps track of how many adjacent squares contain squids, and adjacent Child, which
	 determines if there is a nearby child or not.*/
	int DoA, squid, adjFlag, adjSquids, adjChild;

	/*Squid shoot handles changing the squid var for each object, as well as setting up the
	adjFlag variable for surrounding squares of one that has been shot.*/
	int squid_shoot(squid_square*[9]);

	/*Squid_check looks at the surrounding squares of a given square and increases the 
	adjSquids variable.*/
	void squid_check(squid_square*[9]);

	void print(squid_square*[9]);
};

/*Squid_prep is a function for loading the pointer array with the surrounding squares of the one dictated
by the two integers.  This is mostly used to save space on repeating code blocks.*/
void squid_prep(squid_square*[9], squid_square[][11], int, int);

/*Squid_collateral is the "extra credit" function that uncovers surrounding squares in the event a chosen
square has no surrounding squids.*/
int squid_collateral(squid_square* [9], squid_square[][11], int, int);

int main()
{
	srand((unsigned int)time(NULL));
	const int bigX = 10, bigY = 10;  //Required to be const by Visual Studio for the class array.
	int difficulty, x, y, sq_num, child = 1;
	int aba = 0, bab = 0;

	squid_square* squid_point[9];
	squid_square squid_board[bigX][11];  //Adding an extra member to the second dimension provides useful "off-grid" objects.
	for (int i = 0; i < 9; i++)  //This seemed to be the best way to make sure the pointers were set to default values.
	{
		squid_point[i] = {new squid_square};
	}

	cout << "*ahem ahem*\n";
	cout << "Ahoy there me hearty!\n";
	cout << "Have ye come to help save the schoolchildren from the devilish squids menacing our island home?\n";
	cout << "Of course ye have!\n";
	cout << "We got shoals of the devils writhin' 'cross the bay o' our home!\n";
	cout << "The rules are simple.  Just enter the coordinates of the potential squid you want to shoot.\n";
	cout << "If ye hit a squid, it's dead.  Well done!\n";
	cout << "But be careful!  A fog so heavy ye can't hardly tell the squids from the children!\n";
	cout << "If ye be so foolish as to miss the target, you could kill someone!\n";
	cout << "If that happens, game over!  So try not to miss!\n";
	cout << "Each time you kill a squid, the explosion'll let ye see how they're gatherin' round the innocent children.\n";
	cout << "Use that information to zero in on yer targets and blow them away!\n";
	cout << "If ye hit a squid surrounded by squids, then all the blaggards will go up like tinder.\n";
	cout << "Get lucky enough, and we'll be done by supper!\n";
	cout << "Once all the squid are dead, the day is saved and the children will be so happy!\n";
	cout << "Now down to brass tacks: \n";

	cout << "You'll have to find a group of children being menaced, so you choose how many children to protect!\n";
	cout << "The more to protect, the harder it becomes, so be wary about how many wards ye be taking on!\n";
	cout << "The choice is yours!  We need em all done for, so let the squidd'in begin!\n";

	cout << "\nEnter a positive, whole number between 1 and 100 for the number of children to protect.\n";
	cout << "Easy = 5\n";
	cout << "Medium = 15\n";
	cout << "Hard = 30\n";

	while (!(cin >> difficulty))
	{
		cout << "Try entering a positive, whole number between 1 and 100!.\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	sq_num = (bigX * bigY) - difficulty;//This variable sets up the win condition, meaning when all squid are dead.

	for (int i = 0; i < bigX; i++)
	{
		for (int j = 0; j < bigY; j++)
		{
			squid_board[i][j].squid = 0;
		}
	}

	for (int i = 0; i < sq_num; i++)  //This should randomize location of "children" on the board.
	{
		x = rand() % bigX;  
		y = rand() % bigY;
		while (squid_board[x][y].squid == 1)  
		{
			x = rand() % bigX;  
			y = rand() % bigY;
		}
		squid_board[x][y].squid = 1;
	}

	/*This tells each square how many adjacent squids there are.  This should only run once, so
	it is outside the main game loop.*/
	for (int i = 0; i < bigX; i++)
	{
		for (int j = 0; j < bigY; j++)
		{
			squid_prep(squid_point, squid_board, i, j);
			squid_board[i][j].squid_check(squid_point);
		}
	}

	//system("cls");  //Clear screens for funsies again.  Makes the game much more interactive.  Not used for output demo.

	cout << "\n";

	do  //The main game loop.
	{	

		/*The board is printed first.*/
		cout << "(Y)\n";
		for (int j = bigX - 1; j >= 0; j--)
		{
			if (j < 9)
			{
				cout << j + 1 << "  ";
			}
			else
			{
				cout << j + 1 << " ";
			}
			for (int i = 0; i < bigY; i++)
			{
				squid_prep(squid_point, squid_board, i, j);
				squid_board[i][j].print(squid_point);
				cout << " ";
			}
			cout << "\n";
		}
		cout << "   ";
		for (int j = 0; j < bigY; j++)
		{
			cout << " " << j + 1 << "  ";
		}
		cout << "(X)\n";

		/*This begins the user interaction.  This involves the user selecting a square which is then fired upon,
		thus changing the board for the next pass of the game loop.*/
		cout << "There are " << sq_num << " squid left!\n";
		cout << "Where do you want to fire your cannon?\n";
		cout << "Enter the coordinates of the square you want to target as x y and press enter.\n";
		
		if (!(cin >> x >> y))
		{
			//system("cls");
			cout << "Try that again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (x > bigX || y > bigY || x <= 0 || y <= 0)
		{
			//system("cls");
			cout << "Try that again.\n";
		}
		else
		{
			x = x - 1;
			y = y - 1;
			squid_prep(squid_point, squid_board, x, y);
			int shot = squid_board[x][y].squid_shoot(squid_point);
			if (shot == 1)
			{
			}
			else if (shot == 0)
			{				
				child = 0;
				cout << "Oh my god!  You killed Kenny!\n";
			}
			else if (shot == 2)
			{
				cout << "Luckily, that one was a gimme.  Everybody gets one.\n";				
			}
		}

		/*This assigns collateral damage after a square has been shot.  The first loop makes sure that all the squares are checked.
		After squid_collateral is finished, then comes a check to see how many squids are left on the board.*/
		for (int w = 0; w < bigX; w++)
		{
			for (int t = 0; t < bigX; t++)
			{
				for (int u = 0; u < bigY; u++)
				{
					squid_prep(squid_point, squid_board, t, u);
					squid_collateral(squid_point, squid_board, t, u);
				}
			}
		}
		bab = (bigX * bigY) - difficulty;
		aba = 0;
		for (int t = 0; t < bigX; t++)
		{
			for (int u = 0; u < bigY; u++)
			{
				if (squid_board[t][u].squid == 0)
				{
					aba++;
				}
			}
		}
		aba = aba - difficulty;
		sq_num = bab - aba;
	}while (sq_num > 0 && child != 0);

	cout << "\nGame Over!\n";
}


/*-----------------------The functions for int main.-----------------------------*/

/*The Grand Pointalizer.  This sets up the pointers with the memory addresses of the squares surrounding the one currently dictated by i and j, sometimes known as x and y.
This allows the class functions to then use those pointers to determine which tile to print and how many adjacent squids are around.  It saves a lot of unecessary repeating code.
Each use of this does require all of the pointers to be reset to make sure that old pointers aren't indicating the wrong square, so "off-grid" squares are used as blanks that 
won't add anything.  Whenever pointers for specific coordinates are needed, this function is called.*/
void squid_prep(squid_square* sp[9], squid_square squid_board[][11], int i, int j)
{
	if (i > 0 && i < 9 && i > 0 && j < 9)
	{
		sp[1] = &squid_board[i - 1][j];
		sp[2] = &squid_board[i + 1][j];
		sp[3] = &squid_board[i - 1][j + 1];
		sp[4] = &squid_board[i + 1][j + 1];
		sp[5] = &squid_board[i - 1][j - 1];
		sp[6] = &squid_board[i + 1][j - 1];
		sp[7] = &squid_board[i][j + 1];
		sp[8] = &squid_board[i][j - 1];
	}
	else if (i == 0 && j > 0 && j < 9)
	{
		sp[1] = &squid_board[i][10];
		sp[2] = &squid_board[i + 1][j];
		sp[3] = &squid_board[i][10];
		sp[4] = &squid_board[i + 1][j + 1];
		sp[5] = &squid_board[i][10];
		sp[6] = &squid_board[i + 1][j - 1];
		sp[7] = &squid_board[i][j + 1];
		sp[8] = &squid_board[i][j - 1];
	}
	else if (i == 9 && j > 0 && j < 9)
	{
		sp[1] = &squid_board[i - 1][j];
		sp[2] = &squid_board[i][10];
		sp[3] = &squid_board[i - 1][j + 1];
		sp[4] = &squid_board[i][10];
		sp[5] = &squid_board[i - 1][j - 1];
		sp[6] = &squid_board[i][10];
		sp[7] = &squid_board[i][j + 1];
		sp[8] = &squid_board[i][j - 1];
	}
	else if (i > 0 && i < 9 && j == 0)
	{
		sp[1] = &squid_board[i - 1][j];
		sp[2] = &squid_board[i + 1][j];
		sp[3] = &squid_board[i - 1][j + 1];
		sp[4] = &squid_board[i + 1][j + 1];
		sp[5] = &squid_board[i][10];
		sp[6] = &squid_board[i][10];
		sp[7] = &squid_board[i][j + 1];
		sp[8] = &squid_board[i][10];
	}
	else if (i > 0 && i < 9 && j == 9)
	{
		sp[1] = &squid_board[i - 1][j];
		sp[2] = &squid_board[i + 1][j];
		sp[3] = &squid_board[i][10];
		sp[4] = &squid_board[i][10];
		sp[5] = &squid_board[i - 1][j - 1];
		sp[6] = &squid_board[i + 1][j - 1];
		sp[7] = &squid_board[i][10];
		sp[8] = &squid_board[i][j - 1];
	}
	else if (i == 0 && j == 0)
	{
		sp[1] = &squid_board[i][10];
		sp[2] = &squid_board[i + 1][j];
		sp[3] = &squid_board[i][10];
		sp[4] = &squid_board[i + 1][j + 1];
		sp[5] = &squid_board[i][10];
		sp[6] = &squid_board[i][10];
		sp[7] = &squid_board[i][j + 1];
		sp[8] = &squid_board[i][10];
	}
	else if (i == 0 && j == 9)
	{
		sp[1] = &squid_board[i][10];
		sp[2] = &squid_board[i + 1][j];
		sp[3] = &squid_board[i][10];
		sp[4] = &squid_board[i][10];
		sp[5] = &squid_board[i][10];
		sp[6] = &squid_board[i + 1][j - 1];
		sp[7] = &squid_board[i][10];
		sp[8] = &squid_board[i][j - 1];
	}
	else if (i == 9 && j == 0)
	{
		sp[1] = &squid_board[i - 1][j];
		sp[2] = &squid_board[i][10];
		sp[3] = &squid_board[i - 1][j + 1];
		sp[4] = &squid_board[i][10];
		sp[5] = &squid_board[i][10];
		sp[6] = &squid_board[i][10];
		sp[7] = &squid_board[i][j + 1];
		sp[8] = &squid_board[i][10];
	}
	else if (i == 9 && j == 9)
	{
		sp[1] = &squid_board[i - 1][j];
		sp[2] = &squid_board[i][10];
		sp[3] = &squid_board[i][10];
		sp[4] = &squid_board[i][10];
		sp[5] = &squid_board[i - 1][j - 1];
		sp[6] = &squid_board[i][10];
		sp[7] = &squid_board[i][10];
		sp[8] = &squid_board[i][j - 1];
	}
}

int squid_collateral(squid_square* sp[9], squid_square squid_board[][11], int x, int y)
{
	if (squid_board[x][y].adjFlag == 1 && squid_board[x][y].adjChild == 0 && squid_board[x][y].DoA == -10)
	{
		for (int i = 1; i < 8; i++)
		{
			sp[i]->adjFlag = 1;
			sp[i]->squid = 0;
		}
		squid_board[x][y].DoA = 1;
		squid_board[x][y].squid = 0;
		return 1;
	}
}

/*-------------------------------------The class functions.-------------------------------------------------*/

squid_square::squid_square()
{
	squid = -10;
	adjSquids = 0;
	DoA = -10;
	adjFlag = -10;
	adjChild = 0;
}

int squid_square::squid_shoot(squid_square* sp[9])
{
	//system("cls");
	if (adjChild == 0)
	{
		for (int i = 1; i < 9; i++)
		{
			if (sp[i]->squid == 1)
			{
				sp[i]->adjFlag = 1;
			}
		}
	}
	if (squid == 0)
	{
		cout << "*Splooosh...!*  You missed!\n";
		DoA = 0;
		return 0;
	}
	else if (squid == 1)
	{
		cout << "*ka-BOOOM!*  You hit a squid!\n";
		DoA = 1;
		squid = 0;
		return 1;
	}
}

void squid_square::squid_check(squid_square* sp[9])
{
	for (int i = 1; i < 9; i++)
	{
		if (sp[i]->squid == 1)
		{
			adjSquids += 1;
		}
		else if (sp[i]->squid == 0)
		{
			adjChild += 1;
		}
	}
}

void squid_square::print(squid_square* sp[9])
{
	if (DoA != -10)
	{		
		cout << "(" << adjChild << ")";  
	}
	else if (DoA == -10 && adjFlag == 1)
	{
		cout << "(" << adjChild << ")";
	}
	else
	{
		cout << "( )";
	}
}

