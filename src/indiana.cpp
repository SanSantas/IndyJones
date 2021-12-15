/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Indiana Jones! The man himself.
 * 		Defines his functions
 ***********************************************/

#include "indiana.hpp"
#include <iostream>
using std::cout;
using std::cin;


/**********************************
 * 			Indiana()
 * 
 * Constructor defines base HP and
 * starting coordinates
 *********************************/
Indiana::Indiana()
{
	HP = 20;
    Xpos = 3;
    Ypos = 19;
    direction = 'X';
}

/**********************************
 * 			setHP()
 * 
 * One parameter used to change his
 * HP
 *********************************/
void Indiana::setHP(int HP)
{
	this->HP = HP;
}

/**********************************
 * 			getHP()
 * 
 * 	Returns Indy's current HP
 *********************************/
int Indiana::getHP()
{
	return HP;
}

/**********************************
 * 			setXpos()
 * 
 * 1 parameter used to change his
 * x-coordinate on the 2D space 
 * array
 *********************************/
void Indiana::setXpos(int x)
{
    Xpos = x;
}

/**********************************
 * 			setYpos()
 * 
 * 1 int parameter used to change
 * the y-coordinate in the 2D space
 * array
 *********************************/
void Indiana::setYpos(int y)
{
    Ypos = y;
}

/**********************************
 * 			getXpos()
 * 
 * 	Returns Indy's X-corrdinate
 *********************************/
int Indiana::getXpos()
{
    return Xpos;
}

/**********************************
 * 			getYpos()
 * 
 * 	Returns Indy's Y-coordinate
 *********************************/
int Indiana::getYpos()
{
    return Ypos;
}

/**********************************
 * 			setDirection()
 * 
 * 1 char parameter used to set 
 * Indy's requested direction.
 * Game accepts w/a/s/d and i for
 * inventory, as well as X to quit
 *********************************/
void Indiana::setDirection(char in)
{
    direction = in;
}

/**********************************
 * 			getDirection()
 * 
 * 	Returns Indy's current user-
 * specified direction.
 *********************************/
char Indiana::getDirection()
{
    return direction;
}

/**********************************
 * 			validateDrection()
 * 
 * 	Ensures the user inputs a valid
 * directive for Indy Jones
 *********************************/
bool Indiana::validateDirection()
{
	//Reset the choice if looped
	string input;
	char choice     = 0;
	bool inputBool = false;

	//Take the input as string
	cin >> input;
	
	//Change the first character of input to ascii adjusted integer
	choice = input.at(0);

	setDirection(choice);

	//Prompt the user for reentry of cin failed, and clear the buffer
	if(cin.fail() || input.length() > 1)
	{
		cout << "\n\n   Please enter \"w\",\"a\",\"s\", or \"d\" to choose a direction, \"i\" to use an item, or \"X\" to exit\n\n >> ";
		cin.clear();
		cin.ignore(256, '\n');
	}
	
	//Return true if the user's input is in acceptable range
	else if( choice == 'w' || choice == 'a' || choice == 's' || choice == 'd' || choice == 'i' || choice == 'X')
	{
		cin.clear();
		cin.ignore(256, '\n');
		inputBool = true;
		return inputBool;
	}
	//Prompt user for reentry if they entered an integer if outside acceptable range
	else
	{	
		cout << "\n\n   Please enter \"w\",\"a\",\"s\", or \"d\" to choose a direction, \"i\" to use an item, or \"X\" to exit\n\n  >> ";
	}
}