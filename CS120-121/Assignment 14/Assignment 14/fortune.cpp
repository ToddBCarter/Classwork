#include<iostream>
#include<cstdlib>
using namespace std;

/*This is the fortune program rebuilt as a command line program.
This takes only one number from the user as a way to simplify its
use, as there was no way to explain that the user needed to enter
two numbers unless they had tried and already failed.  Instead,
they are prompted to enter their favorite number, which is then
multiplied with a randomly generated number.*/

int main(int argc, char* argv[])
{	
	srand(time(NULL));
	if (argc != 2) {
		cout << "Try again with your favorite number!\n";
		return 0;
	}

	int lucky;
	int favorite, disliked;
	favorite = atoi(argv[1]);
	disliked = rand() % 100 + 1;
	lucky = (favorite * disliked) % 10;

	cout << endl << "Your lucky number is: " << lucky << endl << endl;

	if (lucky == 0) {
		cout << "...I think that means you're going to die soon." << endl;
	}
	if (lucky > 0 && lucky < 5) {
		cout << "Well, yeah, I could have guessed that.\nHardly needed magic, did I?" << endl;
	}
	if (lucky >= 5 && lucky < 8) {
		cout << "Today is your lucky day, for some reason!  Congrats!" << endl;
	}
	if (lucky == 8) {
		cout << "You've hit the limits of probability.  Congratulations.  Probably means it's lucky, right?" << endl;
	}
	if (lucky == 9) {
		cout << "That was one in a million, kid.  Or at least one in ten." << endl;
	}

	cout << "\nIf you roll again, who knows, perhaps the winds of fortune will blow a different way!\n\n";

	return 0;
}
