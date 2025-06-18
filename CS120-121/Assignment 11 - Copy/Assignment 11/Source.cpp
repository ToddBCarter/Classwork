/*This is a gopher game that has built as an homage to a specific
minigame from a classic video game on Gamecube, Legend of Zelda:
Wind Waker.  This game only takes the theme, and otherwise follows
the gopher game definition, more or less.*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class squid_square
{
private:
	int locX, locY;
public:
	squid_square();
	int squid, DoA, adjSquids;
	string tile;
	void to_squid_or_not_to_squid(int, int, int);
	int squid_shoot();
	void squid_check(squid_square*, squid_square*, squid_square*, squid_square*, squid_square*, squid_square*, squid_square*, squid_square*);
	void print();
	void print2(squid_square*, squid_square*, squid_square*, squid_square*, squid_square*, squid_square*, squid_square*, squid_square*);
};

void fire_cannon(int[10][10]);
void print_board(int);

int main()
{
	srand((unsigned int)time(NULL));
	const int bigX = 10, bigY = 10;  //Required to be const by Visual Studio for the class array.
	int difficulty, x, y, sq_num, sq_chk;
	int cntr = 0;
	
	squid_square squid_board[bigX][11];

	cout << "How many squids do you wish to hunt?\n";
	cout << "The more you have to shoot, the easier the hunt!\n";
	cout << " Enter a positive, whole number between 1 and 100!\n";
	cout << "Easy = 50\n";
	cout << "Medium = 25\n";
	cout << "Hard = 10\n";

	while (!(cin >> difficulty))
	{
		cout << "Try entering a positive, whole number between 1 and 100!.\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	//cout << "adSquids for 9 8 is: " << squid_board[9][8].adjSquids << endl;
	
	//{
	sq_num = difficulty;

	//squid_square* squidPoint; 
	squid_square* sP0;  //For some stupid reason, these have to be declared individually.
	squid_square* sP1;
	squid_square* sP2;
	squid_square* sP3;
	squid_square* sP4;
	squid_square* sP5;
	squid_square* sP6;
	squid_square* sP7;
	squid_square* sP8;

	for (int j = 0; j < bigX; j++)  //The Grand Initializer.
	{
		for (int i = 0; i < bigY; i++)
		{
			sP0 = &squid_board[i][j];
			if (i > 0 && i < 9 && i > 0 && j < 9)  //trigger 1
			{
				sP1 = &squid_board[i - 1][j];
				sP2 = &squid_board[i + 1][j];
				sP3 = &squid_board[i - 1][j + 1];
				sP4 = &squid_board[i + 1][j + 1];
				sP5 = &squid_board[i - 1][j - 1];
				sP6 = &squid_board[i + 1][j - 1];
				sP7 = &squid_board[i][j + 1];
				sP8 = &squid_board[i][j - 1];
			}
			else if (i == 0 && j > 0 && j < 9)  //trigger 2
			{
				sP1 = &squid_board[i][11];
				sP2 = &squid_board[i + 1][j];
				sP3 = &squid_board[i][11];
				sP4 = &squid_board[i + 1][j + 1];
				sP5 = &squid_board[i][11];
				sP6 = &squid_board[i + 1][j - 1];
				sP7 = &squid_board[i][j + 1];
				sP8 = &squid_board[i][j - 1];
			}
			else if (i == 9 && j > 0 && j < 9)
			{
				sP1 = &squid_board[i - 1][j];
				sP2 = &squid_board[i][11];
				sP3 = &squid_board[i - 1][j + 1];
				sP4 = &squid_board[i][11];
				sP5 = &squid_board[i - 1][j - 1];
				sP6 = &squid_board[i][11];
				sP7 = &squid_board[i][j + 1];
				sP8 = &squid_board[i][j - 1];
			}
			else if (i > 0 && i < 9 && j == 0)
			{
				sP1 = &squid_board[i - 1][j];
				sP2 = &squid_board[i + 1][j];
				sP3 = &squid_board[i - 1][j + 1];
				sP4 = &squid_board[i + 1][j + 1];
				sP5 = &squid_board[i][11];
				sP6 = &squid_board[i][11];
				sP7 = &squid_board[i][j + 1];
				sP8 = &squid_board[i][11];
			}
			else if (i > 0 && i < 9 && j == 9)
			{
				sP1 = &squid_board[i - 1][j];
				sP2 = &squid_board[i + 1][j];
				sP3 = &squid_board[i][11];
				sP4 = &squid_board[i][11];
				sP5 = &squid_board[i - 1][j - 1];
				sP6 = &squid_board[i + 1][j - 1];
				sP7 = &squid_board[i][11];
				sP8 = &squid_board[i][j - 1];
			}
			else if (i == 0 && j == 0)
			{
				sP1 = &squid_board[i][11];
				sP2 = &squid_board[i + 1][j];
				sP3 = &squid_board[i][11];
				sP4 = &squid_board[i + 1][j + 1];
				sP5 = &squid_board[i][11];
				sP6 = &squid_board[i][11];
				sP7 = &squid_board[i][j + 1];
				sP8 = &squid_board[i][11];
			}
			else if (i == 0 && j == 9)
			{
				sP1 = &squid_board[i][11];
				sP2 = &squid_board[i + 1][j];
				sP3 = &squid_board[i][11];
				sP4 = &squid_board[i][11];
				sP5 = &squid_board[i][11];
				sP6 = &squid_board[i + 1][j - 1];
				sP7 = &squid_board[i][11];
				sP8 = &squid_board[i][j - 1];
			}
			else if (i == 9 && j == 0)
			{
				sP1 = &squid_board[i - 1][j];
				sP2 = &squid_board[i][11];
				sP3 = &squid_board[i - 1][j + 1];
				sP4 = &squid_board[i][11];
				sP5 = &squid_board[i][11];
				sP6 = &squid_board[i][11];
				sP7 = &squid_board[i][j + 1];
				sP8 = &squid_board[i][11];
			}
			else if (i == 9 && j == 9)
			{
				sP1 = &squid_board[i - 1][j];
				sP2 = &squid_board[i][11];
				sP3 = &squid_board[i][11];
				sP4 = &squid_board[i][11];
				sP5 = &squid_board[i - 1][j - 1];
				sP6 = &squid_board[i][11];
				sP7 = &squid_board[i][11];
				sP8 = &squid_board[i][j - 1];
			}
			squid_board[i][j].squid_check(sP1, sP2, sP3, sP4, sP5, sP6, sP7, sP8);
		}
	}












		for (int i = 0; i < difficulty; i++)  //This should constrain the number of squids placed on the field.
		{
			x = rand() % bigX;  //Generate random numbers between 0 and 9 to produce random square coordinates.
			y = rand() % bigY;
			//cout << "x y at first is: " << x << " " << y << endl;
			while (squid_board[x][y].squid == 1)  //Check to see if a square has already been given a squid.
			{
				x = rand() % bigX;  //If it has, roll for a new square.
				y = rand() % bigY;
				//cout << "x y is: " << x << " " << y << endl;
			}
			if (squid_board[x][y].squid != 1)  //Check one more time to make sure a square doesn't have a squid.  May be unnecessary.
			{
				squid_board[x][y].squid = 1; //Give the square a squid, as it should by now be confirmed not to have one.

				/*The ridiculous checks to gather information about surrounding squids.
				As each squid is handed out, the squares around the chosen square are meant to increment their
				adjSquids by one, indicating their new neighbor squid.
				For some reason, this does not work at all.  Subtracting Y seems to be occurring more than once? Oh shit*/
				if (x > 0 && x < 9 && y > 0 && y < 9)
				{
					cout << "trigger 1";
					squid_board[x - 1][y].adjSquids = squid_board[x - 1][y].adjSquids + 1;
					squid_board[x + 1][y].adjSquids = squid_board[x + 1][y].adjSquids + 1;
					squid_board[x - 1][y - 1].adjSquids = squid_board[x - 1][y - 1].adjSquids + 1;
					squid_board[x + 1][y + 1].adjSquids = squid_board[x + 1][y + 1].adjSquids + 1;
					squid_board[x][y + 1].adjSquids = squid_board[x][y + 1].adjSquids + 1;
					squid_board[x][y - 1].adjSquids = squid_board[x][y - 1].adjSquids + 1;
					squid_board[x - 1][y + 1].adjSquids = squid_board[x - 1][y + 1].adjSquids + 1;
					squid_board[x + 1][y - 1].adjSquids = squid_board[x + 1][y - 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
					cout << " and squid for " << x << " " << y << " is:    " << squid_board[x][y].squid;
					cout << "\ntrig 1 adSquids for 9 8 is: " << squid_board[9][8].adjSquids << endl;
				}
				else if (x == 0 && y > 0 && y < 9)
				{
					cout << "trigger 2";
					squid_board[x + 1][y].adjSquids = squid_board[x + 1][y].adjSquids + 1;
					squid_board[x + 1][y + 1].adjSquids = squid_board[x + 1][y + 1].adjSquids + 1;
					squid_board[x][y + 1].adjSquids = squid_board[x][y + 1].adjSquids + 1;
					squid_board[x][y - 1].adjSquids = squid_board[x][y - 1].adjSquids + 1;
					squid_board[x + 1][y - 1].adjSquids = squid_board[x + 1][y - 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
					cout << "\ntrig 2 adSquids for 9 8 is: " << squid_board[9][8].adjSquids << endl;
				}
				else if (x == 9 && y > 0 && y < 9)
				{
					cout << "trigger 3";
					squid_board[x - 1][y].adjSquids = squid_board[x - 1][y].adjSquids + 1;
					squid_board[x - 1][y - 1].adjSquids = squid_board[x - 1][y - 1].adjSquids + 1;
					squid_board[x][y + 1].adjSquids = squid_board[x][y + 1].adjSquids + 1;
					squid_board[x][y - 1].adjSquids = squid_board[x][y - 1].adjSquids + 1;
					squid_board[x - 1][y + 1].adjSquids = squid_board[x - 1][y + 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
				}
				else if (x > 0 && x < 9 && y == 0)
				{
					cout << "trigger 4";
					squid_board[x - 1][y].adjSquids = squid_board[x - 1][y].adjSquids + 1;
					squid_board[x + 1][y].adjSquids = squid_board[x + 1][y].adjSquids + 1;
					squid_board[x + 1][y + 1].adjSquids = squid_board[x + 1][y + 1].adjSquids + 1;
					squid_board[x][y + 1].adjSquids = squid_board[x][y + 1].adjSquids + 1;
					squid_board[x - 1][y + 1].adjSquids = squid_board[x - 1][y + 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
				}
				else if (x > 0 && x < 9 && y == 9)
				{
					cout << "trigger 5";
					squid_board[x - 1][y].adjSquids = squid_board[x - 1][y].adjSquids + 1;
					squid_board[x + 1][y].adjSquids = squid_board[x + 1][y].adjSquids + 1;
					squid_board[x - 1][y - 1].adjSquids = squid_board[x - 1][y - 1].adjSquids + 1;
					squid_board[x][y - 1].adjSquids = squid_board[x][y - 1].adjSquids + 1;
					squid_board[x + 1][y - 1].adjSquids = squid_board[x + 1][y - 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
				}
				else if (x == 0 && y == 0)
				{
					cout << "trigger 6";
					squid_board[x + 1][y].adjSquids = squid_board[x + 1][y].adjSquids + 1;
					squid_board[x + 1][y + 1].adjSquids = squid_board[x + 1][y + 1].adjSquids + 1;
					squid_board[x][y + 1].adjSquids = squid_board[x][y + 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
				}
				else if (x == 0 && y == 9)
				{
					cout << "trigger 7";
					squid_board[x + 1][y].adjSquids = squid_board[x + 1][y].adjSquids + 1;
					squid_board[x][y - 1].adjSquids = squid_board[x][y - 1].adjSquids + 1;
					squid_board[x + 1][y - 1].adjSquids = squid_board[x + 1][y - 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
				}
				else if (x == 9 && y == 0)
				{
					cout << "trigger 8";
					squid_board[x - 1][y].adjSquids = squid_board[x - 1][y].adjSquids + 1;
					squid_board[x][y + 1].adjSquids = squid_board[x][y + 1].adjSquids + 1;
					squid_board[x - 1][y + 1].adjSquids = squid_board[x - 1][y + 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
				}
				else if (x == 9 && y == 9)
				{
					cout << "trigger 9";
					squid_board[x + 1][y].adjSquids = squid_board[x + 1][y].adjSquids + 1;
					squid_board[x + 1][y + 1].adjSquids = squid_board[x + 1][y + 1].adjSquids + 1;
					squid_board[x][y + 1].adjSquids = squid_board[x][y + 1].adjSquids + 1;
					cout << " and adSquids for " << x << " " << y << " is: " << squid_board[x][y].adjSquids;
				}
				cout << "\n";
			}
		}

		//cout << "adSquids for 9 8 is: " << squid_board[9][8].adjSquids << endl;
	//}

	for (int i = 0; i < bigX; i++)
	{
		for (int j = 0; j < bigY; j++)
		{
			//Identify the surrounding squids, if any

		}
	}

	for (int i = 0; i < bigX; i++)
	{
		for (int j = 0; j < bigY; j++)
		{

		}
	}	

	//When printing board, squids are hidden at first
	// Each subsequent pass of game do/while generates new board
	// Each space will show location of dead squid, empty revealed space, or unrevealed space
	// To generate each space, print out data from each squid, which will change depending on if squid is dead or alive
	// Spaces adjacent to a revealed space need to show how many unrevealed squids they are adjacent to
	// Selecting a square should be handled by asking for a number and a letter
	// When a selection is made, the corresponding square should be changed and the board should update
	// 
	//Board changes when a squid dies, meaning .squid = 0


	do
	{
		cout << "(Y)\n";
		for (int j = 0; j < bigX; j++)
		{
			for (int i = 0; i < bigY; i++)
			{
				sP0 = &squid_board[i][j];
				if (i > 0 && i < 9 && i > 0 && j < 9)
				{
					if (squid_board[i - 1][j].DoA == 0 || squid_board[i - 1][j].DoA == 1)   //Use DoA status of surrounding squares to check adjSquids
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if (squid_board[i + 1][j].DoA == 0 || squid_board[i + 1][j].DoA == 1)   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j - 1].DoA == 0 || squid_board[i][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j + 1].DoA == 0 || squid_board[i][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j + 1].DoA == 0 || squid_board[i + 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j - 1].DoA == 0 || squid_board[i - 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j + 1].DoA == 0 || squid_board[i - 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j - 1].DoA == 0 || squid_board[i + 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i == 0 && j > 0 && j < 9)
				{
					if ((squid_board[i + 1][j].DoA == 0 || squid_board[i + 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j - 1].DoA == 0 || squid_board[i][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j + 1].DoA == 0 || squid_board[i][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j + 1].DoA == 0 || squid_board[i + 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j - 1].DoA == 0 || squid_board[i + 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i == 9 && j > 0 && j < 9)
				{
					if ((squid_board[i - 1][j].DoA == 0 || squid_board[i - 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j - 1].DoA == 0 || squid_board[i][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j + 1].DoA == 0 || squid_board[i][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j - 1].DoA == 0 || squid_board[i - 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j + 1].DoA == 0 || squid_board[i - 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i > 0 && i < 9 && j == 0)
				{
					if ((squid_board[i - 1][j].DoA == 0 || squid_board[i - 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j].DoA == 0 || squid_board[i + 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j + 1].DoA == 0 || squid_board[i][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j + 1].DoA == 0 || squid_board[i + 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j + 1].DoA == 0 || squid_board[i - 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i > 0 && i < 9 && j == 9)
				{
					if ((squid_board[i - 1][j].DoA == 0 || squid_board[i - 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j].DoA == 0 || squid_board[i + 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j - 1].DoA == 0 || squid_board[i][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j - 1].DoA == 0 || squid_board[i - 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j - 1].DoA == 0 || squid_board[i + 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i == 0 && j == 0)
				{
					if ((squid_board[i + 1][j].DoA == 0 || squid_board[i + 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j + 1].DoA == 0 || squid_board[i][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j + 1].DoA == 0 || squid_board[i + 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i == 0 && j == 9)
				{
					if ((squid_board[i + 1][j].DoA == 0 || squid_board[i + 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j - 1].DoA == 0 || squid_board[i][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i + 1][j - 1].DoA == 0 || squid_board[i + 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i == 9 && j == 0)
				{
					if ((squid_board[i - 1][j].DoA == 0 || squid_board[i - 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j + 1].DoA == 0 || squid_board[i][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j + 1].DoA == 0 || squid_board[i - 1][j + 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}
				else if (i == 9 && j == 9)
				{
					if ((squid_board[i - 1][j].DoA == 0 || squid_board[i - 1][j].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i][j - 1].DoA == 0 || squid_board[i][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else if ((squid_board[i - 1][j - 1].DoA == 0 || squid_board[i - 1][j - 1].DoA == 1))   //Use DoA status to check adjSquids of surrounding squares
					{
						cout << "(" << squid_board[i][j].adjSquids << ") ";
					}
					else
					{
						squid_board[i][j].print();
					}
				}

			}
			cout << j + 1 << " \n";
		}
		cout << " ";
		for (int i = 0; i < bigX; i++)
		{
			cout << i + 1 << "   ";
		}
		cout << "  (X)\n";
		for (int i = 0; i < bigX; i++)
		{
			for (int j = 0; j < bigY; j++)
			{
				//cout << "adSquids for " << i << " " << j << " is: " << squid_board[i][j].adjSquids << endl;
				//cout << "Squids are at " << i << " " << j << " is: " << squid_board[i][j].squid << endl;
			}
		}
		for (int i = 0; i < bigX; i++)
		{
			for (int j = 0; j < bigY; j++)
			{
			}
		}
		cout << "Where do you want to fire your cannon?\n";
		cout << "Enter the coordinates of the square you want to target!\n";
		
		if (!(cin >> x >> y))
		{
			cout << "Try that again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			x = x - 1;
			y = y - 1;
		}
		if (squid_board[x][y].squid_shoot() == 1)
		{
			sq_num - 1;
		}

	}while (sq_num > 0);
}

/*The class functions up first.*/

squid_square::squid_square()
{
	locX = 0;
	locY = 0;
	squid = 0;
	tile = "( )";
	adjSquids = 0;
	DoA = -10;
}

void squid_square::to_squid_or_not_to_squid(int difficulty, int bigX, int bigY)
{
	int sq_chk;

	sq_chk = difficulty + rand() % (bigX * bigY);

	if (sq_chk <= difficulty)
	{
		squid == 1;
	}
}

int squid_square::squid_shoot()
{
	if (squid == 0)
	{
		system("cls");
		cout << "*Splooosh...!*  Nothing but brine...\n";
		DoA = 0;
		return 0;
	}
	else if (squid == 1)
	{
		system("cls");
		cout << "*ka-BOOOM!*  You hit a squid!\n";		
		DoA = 1;
		return 1;
	}
}

void squid_square::squid_check(squid_square* one, squid_square* two, squid_square* thr, squid_square* fou, squid_square* fiv, squid_square* six, squid_square* sev, squid_square* eig)
{
	if (one->squid == 1)  //squid_checker, may need elsewhere
	{
		adjSquids = adjSquids + 1;
	}
	if (two->squid == 1)
	{
		adjSquids = adjSquids + 1;
	}
	if (thr->squid == 1)
	{
		adjSquids = adjSquids + 1;
	}
	if (fou->squid == 1)
	{
		adjSquids = adjSquids + 1;
	}
	if (fiv->squid == 1)
	{
		adjSquids = adjSquids + 1;
	}
	if (six->squid == 1)
	{
		adjSquids = adjSquids + 1;
	}
	if (sev->squid == 1)
	{
		adjSquids = adjSquids + 1;
	}
	if (eig->squid == 1)
	{
		adjSquids = adjSquids + 1;
	}
}

void squid_square::print()  //Modify to recognize if squid is dead or not
{
	if (DoA == 0)
	{
		tile = "NIL";
	}
	else if (DoA == 1)
	{
		tile = "X_X";
	}
	else
	{
		cout << tile << " ";
	}

}

void squid_square::print2(squid_square* a, squid_square* b, squid_square* c, squid_square* d, squid_square* e, squid_square* f, squid_square* g, squid_square* h)
{
	if (DoA == 0)
	{
		tile = "NIL";
	}
	else if (DoA == 1)
	{
		tile = "X_X";
	}
	else
	{
		if (a->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (b->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (c->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (d->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (e->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (f->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (g->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (h->DoA == 1)
		{
			cout << "(" << adjSquids << ") ";
		}

		if (a->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (b->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (c->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (d->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (e->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (f->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (g->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
		if (h->DoA == 0)
		{
			cout << "(" << adjSquids << ") ";
		}
	}

}

/*The functions for int main.*/

void squid_check()
{

}