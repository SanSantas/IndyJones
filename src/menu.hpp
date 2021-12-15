/************************************************
 * Author:	Andre Ortega
 * Date:	11/29/2019
 * Description: Header file for menu declaration
 * 		and implementation, used to set/get 
 * 		user inputs with validation. A roll
 * 		function has also been added for this lab.
 ***********************************************/

#ifndef MENU_HPP
#define MENU_HPP

class Menu

{

private:
	
	// Store input validity and user choice within Menu
	int choice;

public:

	Menu();

	// Prints a message depending on which integer is passed
	void print(int);

	// Stores a user choice
	void setChoice(int);

	// Returns the choice passed by a user
	int getChoice(void);

	// Returns true if user-input is within specified range
	bool validate(int, int);	

	// RNG generater between 1 and range
	int roll(int range);

	// Clears screen
	void clear();
};

#endif
