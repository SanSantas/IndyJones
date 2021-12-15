/*******************************************************************
 ** Author:       Andre Ortega
 ** Date:         12/9/2019
 ** Description:  Menu class prints prompts and validates inputs.
		The constructor for this menu program is used to implement
		search and sort functions for Lab 8
*******************************************************************/

#include "menu.hpp"
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Constructor initializes validInput to false to force first-iteration check of user-input
Menu::Menu()
{
}

/*************************************
 *			print()
 *
 *  Prints messages
 * 
 *	Takes an int paramter to determine
 * which message gets printed
 *************************************/
void Menu::print(int message)
{
	if (message == 0)
	{
		cout << "\n\n   THE INDIANA JONES GOLDEN IDOL HEIST SIMULATOR\n\t\t\t\t\t ..copyright pending\n\n";
	}

	if (message == 1)
	{
		cout << "\n\n   What would you like to do?\n\n   1) Enter\n   2) Exit\n\n   ";
	}

	if (message == 2)
	{
		cout << "\n\n   There is a wall in the way.. \n\n";
	}
	if (message == 3)
	{
		cout << "\n\n   There is a cavernous abyss in your path!!\n\n";
	}

	if (message == 4)
	{
		cout << "\n   Indy fell into the hole and took 2 points of fall damage!! \n          Maybe he has something to help him across?\n\n";
	}

	if (message == 5)
	{
		cout << "\n   Enter the item #\n\n   >> ";
	}

	if (message == 6)
	{
		cout << "\n   From the cold ceiling, Indy spots a descending rocky stalactite, he latches it with his whip, and SWINGS across the cavernous abyss!!\n\n";
	}

	if (message == 7)
	{
		cout << "\n   Indy clutches his whip, he's a surgeon with this thing..\n\n";
	}

	if (message == 8)
	{
		cout << "\n   There's a big rock in the way!\n\n";
	}

	if (message == 9)
	{
		cout << "\n   The Golden Idol glows with eminence before Indi's very eyes..\n      ";
		cout << "..Indy wonders if it weighs less than his bag of sand..\n\n";
	}

	if (message == 10)
	{
		cout << "\n   Indy straightens his hat in roguish fashion\n\n";
	}
	if (message == 11)
	{
		cout << "\n   Indy assures himself roguishly that his hat is still straight\n\n";
	}
	if (message == 12)
	{
		cout << "\n   Indy cannot leave without the Idol\n\n";
	}
	if (message == 13)
	{
		cout << "\n   Indy's HP reaches zero after falling prey to another trap. \n\n   He remarks upon his dire situation with a sly one-liner for none to hear, then passes away..\n\n";
	}

	if (message == 14)
	{
		cout << "\n   Indy drinks from his water bottle to restore 10HP!\n\n";
	}

	if (message == 15)
	{
		cout << "\n   Indy puts his cantine to his mouth only to find it empty.\n\n";
	}

	if (message == 16)
	{
		cout << "\n   Indy spots a precariously positioned rock. He shoots it with his trusty sidearm..\n\n";
        cout << "\n   PLINK!\n\n";
		cout << "   Bullseye.\n\n";
	}
	if (message == 17)
	{
		cout << "\n   BASKING in the light from the GOLDEN IDOL, Indiana Jones feels the weight of his bag of sand.\n";
		cout << "      Eyeing the weight of the IDOL, he empties some sand onto the temple floor..\n";
		cout << "         ..and slowly replaces the IDOL with his bag, keeping the IDOL in his possession.\n\n\n\n";
	}
	if (message == 18)
	{
		cout << "\n   Indy idly feels the weight of his bag of sand..\n\n";
	}

	if (message == 19)
	{
		cout << "\n   Indy slyly remarks upon his apparent success\n\n";
	}

	if (message == 20)
	{	cout << "\n\n  INDY HAS ESCAPED SAFELY WITH THE GOLDEN IDOL\n\n";
		cout << "\n\n            Y  O  U      W  I  N  ! !\n\n";
	}

	if (message == 21)
	{
		cout << "\n\n   Indy has walked into an ancient temple trap!\n\n";
	}

	if (message == 22)
	{
		cout << "\n\n      Welcome to the INDIANA JONES GOLDEN IDOL HEIST SIMULATOR\n\n";
		cout << "      We find our hero navigating the ruins of an ANCIENT TEMPLE\n\n";
		cout << "      You must help him find his way to the IDOL using the W-A-S-D keys and pressing [ENTER]\n\n";
		cout << "      On your way you will take damage from hidden TRAP SPACES! It's best to remember where those are..\n\n";
		cout << "      Indy comes equipped with ITEMS to aid his journey, access them by pressing [i] + [ENTER]\n\n";
		cout << "      The GOLDEN IDOL space is marked with an 'I', Indy is the [O] which you will move.\n\n";
		cout << "      Finally, type 'X' and press [ENTER] to exit the simulator.\n\n";
		cout << "      When Indy has the IDOL and leaves the room safely, you win! Good luck!\n\n";
	}
}

void Menu::setChoice(int ch)
{
	choice = ch;
}

/********************************
 *			getChoice()
 *
 *	Returns the choice made 
 *	by the user to be passed
 *	into proper variables
 * *****************************/

int Menu::getChoice()
{
	return choice;
}

/********************************
 * 		Validate()
 *
 *	Function takes two integers
 *	to set the acceptable 
 *	range of user inputs. 
 *	Returns false if the user
 *	input is inadequate
 ********************************/

bool Menu::validate(int bottom, int top)
{
	//Reset the choice if looped
	string input;
	int choice     = 0;
	bool inputBool = false;

	//Take the input as string
	cin >> input;
	
	//Change the first character of input to ascii adjusted integer
	choice = static_cast<int>(input.at(0)-48);

	setChoice(choice);

	//Prompt the user for reentry of cin failed, and clear the buffer
	if(cin.fail() || input.length() > 1)
	{
		cout << "   Please enter an integer between " << bottom << " and " << top << ".\n";
		cin.clear();
		cin.ignore(256, '\n');
	}
	
	//Return true if the user's input is in acceptable range
	else if( choice >= bottom && choice <= top )
	{
		cin.clear();
		cin.ignore(256, '\n');
		inputBool = true;
	}
	//Prompt user for reentry if they entered an integer if outside acceptable range
	else
	{	
		cout << "   Please enter an integer between " << bottom << " and " << top << ".\n   ";
	}

    return inputBool;
}

/***********************************
 *			Roll()
 *
 *   Simulates a die roll between
 * one and the maximum input range,
 * returns the random number from
 * within the passed parameter range
 **********************************/
int Menu::roll(int range)
{
	int roll = rand() % range + 1;
	return roll;
}

/***********************************
 * 			Clear()
 * 
 *	 Clears the screen.
 * 
 ***********************************/
void Menu::clear()
{	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // lololol
}
