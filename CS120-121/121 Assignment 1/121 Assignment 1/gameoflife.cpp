#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
#include"life.h"

int main()
{
	srand((unsigned int)time(NULL));
	
	life lifeBoard;

	int xx = 0, yy = 0, iti;
	char ask = 'n', ask3 = 'n';

	do
	{
		lifeBoard.print();
	
		cout << "\n\nWould you like to enter coordinates?  Y/N";
		cout << "\nBe gentle, I break easily." << endl;
		cin >> ask;
		if (ask == 'y' || ask == 'Y')
		{
			while (xx != -1 && yy != -1)
			{
				/*The variables for x and y switch due to aesthetics.
				This way means the bottom left corner of the board is 
				the origin relative to what the user sees.*/
				cout << "\n\nPlease input coordinates as xx yy and press enter.  When finished, input -1 -1 and press enter." << endl;
				cin >> yy >> xx;
				xx = (rows - xx) + 1;
				lifeBoard.setDoA(xx, yy);
				lifeBoard.print();
			}
		}
		else
		{
			cout << "\n\nWould you like to randomize?  Y/N" << endl;
			cin >> ask;
			if (ask == 'y' || ask == 'Y')
			{
				lifeBoard.randomizer();
				lifeBoard.print();
			}
		}

		cout << "\n\nHow many iterations would you like to run?" << endl;
		cin >> iti;
		if (iti > 0)
		{
			lifeBoard.run(iti);
		}
		else
		{
			iti = rand() % 150 + 1;
			cout << "You have selected: " << iti << " iterations to run." << endl;
		}

		cout << "\n\nWould you like to play more?  Y/N\n\n";
		cin >> ask3;

	}while (ask3 == 'y' || ask3 == 'Y');

	cout << "\n\nGoodbye!\n" << endl;
}