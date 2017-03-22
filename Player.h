/*Player Class Header Player manages Player class
Operations :
Construtor of Player Class
Initialize class members
read data from file into members
write formatted data to an output file
------Additions from Program 1 Player.h------------
get and set functions that return specified class member(s)
need to facilitate comapare functions player data is private
*/
#include <iostream>
#include <fstream>  // Using for files
#include <string>   // Using for strings
#include <iomanip>  // Using to manipulate format

using namespace std;

/// Declare a class for Batter names
class Player
{
	// Class Members 
	string m_FName; // First Name
	string m_LName; // Last Name
	string m_Pos;   // Batters position
	float  m_Bavg;  // Batters Average

public:
	/// default Player Contructor
	Player();

	// Public member functions
	void initialize(string, string, string, float);// Initializes Data	
	void ReadFile(istream &);// Reads one line of Player information from input file
	void WriteString(ostream &);// Writes Player information to output file

								//Adding functionality to compare items to support search functions
	bool Greater(const Player &);	//Greater than returns true if the player is greater than the one passed in
	bool lessThan(const Player &);	// lessThan()  : bool True if the date is less than the on Passed in
	bool Equal(const Player &);		// Equal() : Bool Returns true if the player is equal to the one passed in

									// Define gets and sets for Debugging or future use 
	double getBattingAverage();
	string getFirstName();
	string getLastName();
	string getFullName();
	string getPosition();



};

