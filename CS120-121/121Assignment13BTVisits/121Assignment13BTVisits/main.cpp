/*This is the amalgamated binary search tree that has resulted
from Assignment 11, 12, and currently 13.

Note:  The main program breaks easily, so be gentle.

Both files were taken from Kaggle, one being the villagers.csv and the other
being the construction.csv.  construction.csv was chosen for its structural
similarity to villagers.csv.

Extracting data from the files is done in main() and not as a separate function.


----------For Assignment 13:--------------
Two functions were created, reverseCapitalize and reCapitalize, to be passed
to the nodes in the tree created from the villagers and construction lists.
These functions are very similar in that they both alter capitalization.

reCapitalize will correctly capitalize a name, meaning with the first letter
capitalized and the remaining ones lowercase.

reverseCapitalize will lowercase the first letter and capitalize the rest.

In effect, they reverse one another.  Running the same one repeatedly will
not change the list, while running reverseCapitalize first can then be
corrected by running reCapitalize.  This can be done by the user interface.

The user menu in main() has been refitted to display only Assignment 13 options.
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cctype> /*cctype used for raising/lowering case.*/
using namespace std;

#include"Record.h"
#include"TreeNode.h"
#include"BinaryTree.h"

//typedef void (*visitor)(record);  /*Declaring the function pointer typedef.*/

/*These two functions are the ones to be visited on the nodes.*/
void reverseCapitalize(record*);
void reCapitalize(record*);

int main()
{
	/*Assignment 13: Declaring the function ponter.*/
	void (*visitor)(record*);

	/*
	The declared strings are used for:	
	dataLine - Used to capture the full line which is then separated into name and data.
	name - Used to capture the name from each line of the file.
	data - Used to capture the rest of the information from each line.
	uName - The name to be searched.
	yesNo - Used in the loops for requesting user information.
	species - Used to store the second block of characters between the first and second commas.
		- Not actually used in Assignment 13.
	uFileChoice - Letting the user pick the file.
	*/
	string dataLine, name, data, uName, yesNo;
	string species, uFileChoice;

	/*These variables are the location information for extracting the names and data.*/
	int firstcomma, secondcomma, restofline;
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
		species, and remaining information into their variables, then inserting into the tree.
		Don't worry about the species string, we don't talk about the species string.*/
		while (!recFile.eof())
		{
			getline(recFile, dataLine);
			firstcomma = dataLine.find_first_of(",", 0);
			name = dataLine.substr(0, firstcomma);
			secondcomma = dataLine.find_first_of(",", firstcomma + 1);
			if (firstcomma != -1 && secondcomma != -1)  /*Ugly way of eliminating an extra line.*/
			{
				species = dataLine.substr(firstcomma + 1, ((secondcomma - firstcomma) - 1));
				restofline = dataLine.length();  //restofline uses length() to find the end of the line.
				data = dataLine.substr((secondcomma + 1), restofline);  //Starting one position after the comma until the full length of the line.
				dudes.insert(name, species, data);  //Calling tree::insert().
			}
		}

		do /*This is the main loop that controls the function menu.  Not many comments here as this consists mostly
		   of cout and if statements.  The fun stuff is in the header files.*/
		{
			cout << "\n\nWhat would you like to do?" << endl;
			cout << "(1) Capitalize the first letter and decapitalize the rest of the letters for all keys." << endl;
			cout << "(2) Do the same as (1) for a specified key." << endl;
			cout << "(3) Do the same as (1) for a specified subset of keys." << endl;
			cout << "(4) De-capitalize the first letter and capitalize the remaining letters for all keys." << endl;
			cout << "(5) Do the same as (4) for a specified key." << endl;
			cout << "(6) Do the same as (4) for a specified subset of keys." << endl;
			cout << "(7) Infix print all keys." << endl;
			cin >> uCh;  /*taking the user Choice for the menu.*/

			if (uCh == 1)
			{
				cout << "Properly capitalizing all keys..." << endl;
				visitor = reCapitalize;
				dudes.visit(visitor);  
				cin.ignore();
			}
			else if (uCh == 2)
			{
				cout << "Which key would you like to capitalize?" << endl;
				cout << "If you are looking at villagers, I suggest: aNNALISE" << endl;
				cout << "If you are looking at construction, I suggest: bASIC DOOR" << endl;
				cout << "Capitalization matters!" << endl;
				cin.ignore();
				getline(cin, uName);
				visitor = reCapitalize;
				dudes.keyVisit(visitor, uName);
			}
			else if (uCh == 3)
			{
				cout << "Which substring's keys would you like to capitalize?" << endl;
				cout << "If you are looking at villagers, I suggest: Mouse" << endl;
				cout << "If you are looking at construction, I suggest: Resident Services" << endl;
				cout << "Capitalization matters!" << endl;
				cin.ignore();
				getline(cin, uName);
				visitor = reCapitalize;
				dudes.dataVisit(visitor, uName);
			}
			else if (uCh == 4)
			{
				cout << "De-capitalizing all keys..." << endl;
				visitor = reverseCapitalize;
				dudes.visit(visitor);
				cin.ignore();
			}
			else if (uCh == 5)
			{
				cout << "Which key would you like to de-capitalize?" << endl;
				cout << "If you are looking at villagers, I suggest: Annalise" << endl;
				cout << "If you are looking at construction, I suggest: basic door" << endl;
				cout << "Capitalization matters!" << endl;
				cin.ignore();
				getline(cin, uName);
				visitor = reverseCapitalize;
				dudes.keyVisit(visitor, uName);
			}
			else if (uCh == 6)
			{
				cout << "Which substring's keys would you like to de-capitalize?" << endl;
				cout << "If you are looking at villagers, I suggest: Mouse" << endl;
				cout << "If you are looking at construction, I suggest: Resident Services" << endl;
				cout << "Capitalization matters!" << endl;
				cin.ignore();
				getline(cin, uName);
				visitor = reverseCapitalize;
				dudes.dataVisit(visitor, uName);
			}
			else if (uCh == 7)
			{
				cin.ignore();
				dudes.infixPrint();
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


/*These are the two visitor functions.
They use some string trickery to capitalize, or
de-capitalize, the first letter of a name-string,
and then do the reverse to the remainder.*/
void reverseCapitalize(record * r)
{
	//cout << "in function Test" << endl;
	char z;
	z = r->name.at(0);
	//cout << r->name.at(0);
	z = tolower(z);
	r->name.at(0) = z;
	//cout << r->name.at(0);

	for (int i = 1; i < r->name.length(); i++)
	{
		z = r->name.at(i);
		z = toupper(z);
		r->name.at(i) = z;
	}
}

void reCapitalize(record* r)
{
	//cout << "in function Test" << endl;
	char z;
	z = r->name.at(0);
	//cout << r->name.at(0);
	z = toupper(z);
	r->name.at(0) = z;
	//cout << r->name.at(0);
	for (int i = 1; i < r->name.length(); i++)
	{
		z = r->name.at(i);
		z = tolower(z);
		r->name.at(i) = z;
	}
}