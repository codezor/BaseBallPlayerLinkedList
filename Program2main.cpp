// Compiler:   Microsoft Visual Studio Community 2015 
// Version:    14.0.25431.01 Update 3
// Program 2 
//
// Programmer: Cody Crofford
// Date:       Febuary 8, 2017
// Course:     CS 221
// Section:    2
//
// Purpose:
// Read file with baseball players name, class, and batting average 
// Write to output file a formatted 
//----------------------------------------------------------------------------------------------------------------------------
// Summary of the program:
// 1. Prompt the user for the input and output file names.DO NOT hardcode file names into your program.
// 2. Open input file
// 3. Read each player and add them to your PlayerList
// 4. Keep track of the number of players in the list
// 5. Store the players in the list in alphabetical order(lastname then firstname in the event of two people with the same last name).You should be adding them in between other nodes as appropriate
// 6. Test your find operation a couple of times.This can be hardcoded into your program.You do not have to prompt the user for players, unless you wish to.Just make sure you test for players that exist and that do not
// 7. Open an output file
// 8. Write each player from the list into the output file, along with any other output required by the assignment
// 9. Store players in a linked list in alphabetical order by last name 
//	Operations: 
// 		1. Default Contructor 
//		2. Destructor
//		3. Add a Player to the List
//		4. Iterate the List(enables list traversing)
//		5. Clear out the List to make empty
//		6. Test if the List is empty
//		7. Get the Size of the List
//		8. Find a player in the List(get)


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "PlayerList.h"
#include "Player.h"
using namespace std;


int main(void)
{
	Player myPlayer;
	PlayerList myPlayerList;

	ifstream inFile;
	ofstream outFile;
	char inputFileName[50];
	char outputFileName[50];

	int m_length;
	cout << "Please enter the name of your input data file: ";
	cin >> inputFileName;

	inFile.open(inputFileName);
	if (inFile.fail()) {  // file open failed
		cout << "\nError opening input file.  Cannot process player data. \nExiting Program.\n" << endl;
		return 1;		  // NOTE THIS IS THE ONLY TIME I ALLOW AN EMBEDDED RETURN or BREAK type exit IN A PROGRAM
	}
	getchar();
	// file opened successfully 
	//playerCount = 0;

	while (!inFile.eof()) // as long as there are lines of data to be read in
	{   		 
		myPlayer.ReadFile(inFile); // read in a player
		
		myPlayerList.add(myPlayer); // store in list
		cout << "read\n";
	}

	inFile.close();
	myPlayerList.moveToStart();
	m_length = myPlayerList.getSize();

	cout << "what do you want to name your outoutfile? ";
	cin >> outputFileName;
	outFile.open(outputFileName);
	outFile << "The following: " << m_length <<"Players were in the File\n"<< endl;

	while (myPlayerList.getNext(myPlayer))
	{
		myPlayer.WriteString(outFile);
	}
	//getchar();

	myPlayer.initialize("Rafael", "Furcal", "SS", 0.281F);
	bool found = myPlayerList.findPlayer(myPlayer);
	string sfound = found ? "Player Found" : "Player not Found";
	cout << sfound << "\n";
	outFile.close();
	//getchar();
	
	return 0;
	
}