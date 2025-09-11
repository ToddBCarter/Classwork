/*This is a simple program to search through the list of data
taken from the record.txt file provided by the assignment using
a binary search tree.*/

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
	dataLine - Used to capture the full line which is then separated into name and data.
	name - Used to capture the name from each line of the file.
	data - Used to capture the rest of the information from each line.
	uName - The name to be searched.
	yesNo - Used in the loop for requesting user information.
	*/
	string dataLine, name, data, uName, yesNo;

	int firstcomma, restofline;  //The are the location information for extracting the names and data.

	tree dudes;  //The name of the tree being used.

	ifstream recFile;  //Declaring the file variable.
	recFile.open("records.txt");  //Opening the file from the provided .txt.
	getline(recFile, dataLine);  //Initial getline eliminates the line of column descriptions.

	/*This loop shears information from the .csv file one line at a time, putting the name
	and remaining information into their variables, then inserting into the tree.*/
	do
	{
		getline(recFile, dataLine);
		firstcomma = dataLine.find_first_of(",", 0);
		name = dataLine.substr(0, firstcomma);
		restofline = dataLine.length();  //restofline uses length() to find the end of the line.
		data = dataLine.substr((firstcomma + 1), restofline);  //Starting one position after the comma until the full length of the line.

		dudes.insert(name, data);  //Calling tree::insert().

	} while (!recFile.eof());  //The loop continues until the end of the file.

	yesNo = "N";  //Setting the loop variable.

	do
	{
		record stuff;  /*This is the record that is passed by reference.  
					   Declaring it in the loop scope allows it to reset 
					   for multiple searches in a row.*/

		cout << "\nWho do you want to search for?" << endl;
		cin >> uName;
		dudes.find(uName, stuff);
		
		/*Requesting if the user wants to continue or not.*/
		cout << "\nDo you want to search again?  Enter Y or N and press enter." << endl;
		cin >> yesNo;

	} while (yesNo == "y" || yesNo == "Y");

	recFile.close();  //Closing the file for hygiene.
}