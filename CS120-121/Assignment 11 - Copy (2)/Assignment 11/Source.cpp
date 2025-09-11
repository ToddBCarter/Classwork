/*This is a gopher game that has been built as an homage to a specific
minigame from a classic video game on Gamecube, Legend of Zelda:
Wind Waker.  This game only takes the theme, and otherwise follows
the gopher game definition, more or less.  The concept is that you are
hunting squids on the high seas using a cannon, and you have to figure
out where the squids are in order to hit them as you go.  

Though this is a spiritual match for the gopher game, the mechanics differ
a bit to make things interesting.  Rather than the square that is selected 
showing adjacent gophers, the adjacent squares of the one selected instead 
show how many gophers they each border, if any.  The selected square will
then instead show if it was a miss or a dead squid.

The program uses a class to establish each square of the map, with the 
objects held in a two-dimensional array.  These objects then store data 
about the presence of a squid, the presence of adjacent squids, and whether 
its squid is dead or alive.  An awkward system of pointers is then used to 
pass and update that data.  This does mean there is only a single 2D array, 
but using two arrays is hopefully a suggestion, not a requirement.*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class squid_square
{
private:
	int DoA;
public:
	squid_square();
	/*These functions can be read as Adjacent Squids, which keeps track of how many
	adjacent squares contain squids, Adjacent Flag which is used to spread out the collateral
	damage, and squid, which indicates if the object has a squid or not.*/
	int squid, adjFlag, adjSquids;
	int squid_shoot(squid_square*[9]);
	void squid_check(squid_square*[9]);
	void print(squid_square*[9]);
};

void squid_prep(squid_square*[9], squid_square[][11], int, int);
void squid_collateral(squid_square* [9], squid_square[][11], int, int);

int main()
{
	srand((unsigned int)time(NULL));
	const int bigX = 10, bigY = 10;  //Required to be const by Visual Studio for the class array.
	int difficulty, x, y, sq_num, sq_chk, hull = 4;
	int cntr = 0;

	squid_square* squid_point[9];
	squid_square squid_board[bigX][11];  //Adding an extra member to the second dimension provides useful "off-grid" objects.
	for (int i = 0; i < 9; i++)  //This seemed to be the best way to make sure the pointers were set to default values.
	{
		squid_point[i] = {new squid_square};
	}

	cout << "*ahem ahem*\n";
	cout << "Ahoy there me hearty!\n";
	cout << "Have ye come to help save us from the devilish squids hiding in the deeps?\n";
	cout << "Of course ye have!\n";
	cout << "The rules are simple.  Just enter the coordinates of the potential squid you want to shoot.\n";
	cout << "If ye hit a squid, it's dead.  Well done!\n";
	cout << "But be careful!  If ye miss, ye run the risk of blowing a hole in yer boat!\n";
	cout << "If that happens, game over!  So try not to miss!\n";
	cout << "Regardless of if ye hit or miss, the number of tentacles around where ye shot landed might tell ye how many squids be lurking nearby.\n";
	cout << "Use that information to zero in on yer targets and blow them away!\n";
	cout << "Once all the squids are dead, the day is saved!\n";
	cout << "Now down to brass tacks: \n";
	cout << "We got shoals of the devils writhin' 'cross the bay o' our home.\n";
	cout << "That means ye can pick yer targets as ye please!  Choose a group of the size ye like, and get shootin'!\n";
	cout << "The more you have to shoot, the easier the hunt!\n";
	cout << "But, if ye be clever and ready to roll the dice, well placed shots might scare out smaller shoals, even if ye miss.\n";
	cout << "The choice is yours!  We need em all done for, so let the squidd'in begin!\n";

	cout << "\nEnter a positive, whole number between 1 and 100 for the number of squids to hunt.\n";
	cout << "Easy = 90\n";
	cout << "Medium = 75\n";
	cout << "Hard = 30\n";
	cout << "Risk it for the biscuit = 5\n";  //The collateral function means this is fast, but risky.  You have to miss at least once to even have a chance at all.

	while (!(cin >> difficulty))
	{
		cout << "Try entering a positive, whole number between 1 and 100!.\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	sq_num = difficulty;  //This variable sets up the win condition, meaning when all squid are dead.

	for (int i = 0; i < difficulty; i++)  //This should constrain the number of squids placed on the field.
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
		cout << "(Y)\n";
		for (int j = bigX - 1; j >= 0; j--)
		{
			if (j < 9)
			{
				cout << j + 1 << "  ";  //Makes the board prettier.
			}
			else
			{
				cout << j + 1 << " ";
			}
			for (int i = 0; i < bigY; i++)
			{
				squid_prep(squid_point, squid_board, i, j);  //squid_prep is a space saving function.  It is called often.
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
			if (squid_board[x][y].squid_shoot(squid_point) == 1)
			{
				sq_num -= 1;
			}
			else
			{				
				hull = rand() % 4;  //This gives roughly a one in four chance of an instant loss due to missing a squid.
				if (hull == 0)
				{
					cout << "You shot your own boat!  You're lost to the squid-wracked depths!\n";
				}
				else
				{
					cout << "Nearly blew out a deckboard!  Be careful!\n";
				}
			}
		}

		/*This assigns collateral damage after a square has been shot.  The first for loop makes sure that all the squares are checked.*/
		for (int t = 0; t < bigX; t++)
		{
			for (int i = 0; i < bigX; i++)
			{
				for (int j = 0; j < bigY; j++)
				{
					squid_prep(squid_point, squid_board, i, j);
					squid_collateral(squid_point, squid_board, i, j);
				}
			}
		}

		if (sq_num <= 0)
		{
			cout << "\nYou did it!  You eradicated the squid menace and saved us all!  Yaaay Yaaayy Hooray Yaaayyy...!\n";
		}

	}while (sq_num > 0 && hull != 0);

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

/*The collateral damage function that spreads the damage outwards from wherever a shot lands.  To stop
nearly the entire map from completing with every shot taken when there are few squids on the board, random 
numbers are used as limitations on how many squares will be revealed in this manner.*/
void squid_collateral(squid_square* sp[9], squid_square squid_board[][11], int x, int y)
{
	if (squid_board[x][y].adjFlag == 1 && squid_board[x][y].adjSquids == 0)
	{
		for (int i = 1; i < 8; i++)
		{
			sp[i]->adjFlag = 1;
		}
	}
}

/*-------------------------------------The class functions.-------------------------------------------------*/

squid_square::squid_square()
{
	squid = 0;
	adjSquids = 0;
	DoA = -10;
	adjFlag = -10;
}

int squid_square::squid_shoot(squid_square* sp[9])
{
	//system("cls");
	if (adjSquids == 0)
	{
		for (int i = 1; i < 9; i++)
		{
			if (sp[i]->squid == 0)
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
			adjSquids = adjSquids + 1;
		}
	}
}

void squid_square::print(squid_square* sp[9])
{
	if (DoA == -10 && adjFlag == 1)
	{
		cout << "(" << adjSquids << ")";
	}
	else if (DoA == 0)
	{
		cout << "MIS";
	}
	else if (DoA == 1)
	{
		cout << "X_X";
	}
	else
	{
		if (sp[1]->DoA == 1 || sp[2]->DoA == 1 || sp[3]->DoA == 1 || sp[4]->DoA == 1 || sp[5]->DoA == 1 || sp[6]->DoA == 1 || sp[7]->DoA == 1 || sp[8]->DoA == 1 || sp[1]->DoA == 0 || sp[2]->DoA == 0 || sp[3]->DoA == 0 || sp[4]->DoA == 0 || sp[5]->DoA == 0 || sp[6]->DoA == 0 || sp[7]->DoA == 0 || sp[8]->DoA == 0)
		{
			cout << "(" << adjSquids << ")";
		}
		else
		{
			cout << "( )";
		}
	}
}

