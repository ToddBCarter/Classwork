/*This is the amalgamated binary search tree that has resulted
from Assignment 11 and 12.

Note:  There are definitely parts of this that are unnecessary, useless,
and redundant.  Limited time means limited cleanup, as long as it works.
Remember, the main program breaks easily, so be gentle.

For Assignment 12:

All functions suggested by the assignment were achieved.

They are:

erase() in BinaryTree.h, the delete function.
listings() in BinaryTree.h, the list of keys function.
prefixPrint() in BinaryTree.h, the print-in-prefix-notation function.
treeDepth() in BinaryTree.h, the depth function.
subCounter() in BinaryTree.h, the function to count instances of a substring.
totalCounter() in BinaryTree.h, the count-all-entries function.

The functionality to choose a file is located in main and does not have its
own function, as that was not a requirement.

Both files were taken from Kaggle, one being the villagers.csv and the other
being the construction.csv.  Kaggle can be used to verify the results of
the functions in this assignment.
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

#include"Record.h"
#include"TreeNode.h"
#include"BinaryTree.h"

int main()
{
	/*
	The declared strings are used for:

	From Assignment 11:
	dataLine - Used to capture the full line which is then separated into name and data.
	name - Used to capture the name from each line of the file.
	data - Used to capture the rest of the information from each line.
	uName - The name to be searched.
	yesNo - Used in the loops for requesting user information.

	From Assignment 12:
	species - Used to store the second block of characters between the first and second commas.
	uSpecies - Letting the user pick the species.
	uFileChoice - Letting the user pick the file.
	*/
	string dataLine, name, data, uName, yesNo;

	string species, uSpecies, uFileChoice;

	int firstcomma, secondcomma, restofline;  //These are the location information for extracting the names and data.
	int fileChoice, uCh;
	ifstream recFile;  //Declaring the file variable.
	

	yesNo = "N";  //Setting the loop variable.

	do  /*This do-while controls the file selection.*/
	{
		tree dudes;  //The name of the tree being used.
		record stuff;  /*This is the record that is passed by reference.
					   Declaring it in the loop scope allows it to reset
					   for multiple searches in a row.*/


		/*Starting with the file request: */
		cout << "What would you like to search? Villagers or construction items?" << endl;
		cout << "(1)  Villagers" << endl;
		cout << "(2)  Construction items" << endl;

		cin >> fileChoice;

		if (fileChoice == 1)
		{
			uFileChoice = "villagers.txt";
		}
		else if (fileChoice == 2)
		{
			uFileChoice = "construction.txt";
		}

		recFile.open(uFileChoice);  //Opening the file from the provided .txt.
		getline(recFile, dataLine);  //Initial getline eliminates the line of column descriptions.

		/*This loop shears information from the .csv file one line at a time, putting the name, 
		species, and remaining information into their variables, then inserting into the tree.*/
		while (!recFile.eof())
		{
			getline(recFile, dataLine);
			firstcomma = dataLine.find_first_of(",", 0);
			name = dataLine.substr(0, firstcomma);
			secondcomma = dataLine.find_first_of(",", firstcomma+1);
			if (firstcomma != -1 && secondcomma != -1)  /*Ugly way of eliminating an extra line.*/
			{
				species = dataLine.substr(firstcomma+1, ((secondcomma - firstcomma)-1));
				restofline = dataLine.length();  //restofline uses length() to find the end of the line.
				data = dataLine.substr((secondcomma + 1), restofline);  //Starting one position after the comma until the full length of the line.
				dudes.insert(name, species, data);  //Calling tree::insert().
			}
		}

		do /*This is the main loop that controls the function menu.  Not many comments here as this consists mostly
		   of cout and if statements.  The fun stuff is in the header files.*/
		{
			cout << "\n\nWhat would you like to do?" << endl;
			cout << "(1) Find the total number of entries." << endl;
			cout << "(2) Find the number of iterations of a given subtring." << endl;
			cout << "(3) Calculate the max depth of the tree." << endl;
			cout << "(4) Print all the keys in prefix order." << endl;
			cout << "(5) Print a list of all the keys connected to a substring." << endl;
			cout << "(6) Delete something." << endl;
			cin >> uCh;

			if (uCh == 1)
			{
				cin.ignore();
				dudes.totalCounter();
			}
			else if (uCh == 2)
			{
				cout << "\nWhich substring would you like to search for?" << endl;
				cout << "If you are looking at villagers, I suggest: Dog" << endl;
				cout << "If you are looking at construction, I suggest: iron" << endl;
				cout << "Capitialization matters!" << endl;
				cin.ignore();
				getline(cin, uName);
				dudes.subCounter(uName);
			}
			else if (uCh == 3)
			{
				cin.ignore();
				dudes.treeDepth();
			}
			else if (uCh == 4)
			{
				cin.ignore();
				dudes.prefixPrint();
			}
			else if (uCh == 5)
			{
				cout << "Which substring would you like to search for?" << endl;
				cout << "If you are looking for villagers, I suggest: Cat" << endl;
				cout << "If you are looking for construction, I suggest: House" << endl;
				cout << "Capitialization matters!" << endl;
				cin.ignore();
				getline(cin, uName);
				cout << "\n";
				dudes.listings(uName);

			}
			else if (uCh == 6)
			{
				cout << "What do you want to erase?" << endl;
				cout << "If you are looking to remove a villager, I suggest: Bill" << endl;
				cout << "If you are looking to remove a construction item, I suggest: common door" << endl;
				cout << "Capitialization matters!" << endl;
				cin.ignore();
				getline(cin, uName);
				cout << "\n";
				dudes.erase(uName);
			}
			yesNo = "n";
			cout << "\n\nWould you like to perform another action?  Please type Y or N and hit enter." << endl;
			getline(cin, yesNo);

		} while (yesNo == "y" || yesNo == "Y");
		yesNo = "n";
		cout << "\n\nWould you like to choose another file?  Please type Y or N and hit enter." << endl;
		getline(cin, yesNo);
		cout << "\n";

		if (yesNo == "y" || yesNo == "Y")
		{
			recFile.close();
		}			

	} while (yesNo == "y" || yesNo == "Y");

	cout << "\n\nGoodbye!" << endl;

	recFile.close();  //Final closing of the file.
}