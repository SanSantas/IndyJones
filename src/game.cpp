/*******************************************************************
 ** Author:       Andre Ortega
 ** Date:         12/9/2019
 ** Description:  THE GAME executes upon declaration of the class
		in main.cpp from the game class constructor. 
*******************************************************************/

#include "game.hpp"
#include "menu.hpp"
#include "indiana.hpp"
#include "space.hpp"
#include "spaceBlank.hpp"
#include "spaceHole.hpp"
#include "spaceTrap.hpp"
#include "spaceRock.hpp"
#include "link.hpp"
#include "item.hpp"
#include <iostream>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Constructor runs program
Game::Game()
{
	bool validInput = false;				// Initalize variables needed for menu
	bool quit 		= false;
	srand(time(0));							// Seed rand to make a new board each playthrough
	Menu menu;
	menu.clear();
	menu.print(0);

	while(!quit)
	{

		menu.print(1);
		validInput = false;
		menu.setChoice(0);

		// Validation
		while(!validInput)
		{	validInput = menu.validate(1, 2);	}

		if(menu.getChoice() == 1)
		{
			// Summon his majesty
			Indiana Jones;

			// Direction tracks user's desired move
			char direction;

			// Initialize series of bools for varying scenarios
			bool gameOver 	= false;
			bool wins		= false;
			bool hasIdol    = false;	// If indy has the idol
			bool drankWater = false;	// If he drank his water
			bool straightHat = false;	// Is his hat straight?
			bool across     = false;	// Has he crossed the cavernous abyss?

			Link inventory; // Generate Indy's inventory and equip him with his classic set

			Item * sandbag = new Item("Bag of Sand");		// Mandatory Item
			inventory.addHead(sandbag);

			Item * sidearm = new Item("Trusty Sidearm");	// No real use as of this build
			inventory.addHead(sidearm);

			Item * bottle = new Item("Water Bottle");		// Heals Indy
			inventory.addHead(bottle);

			Item * hat = new Item("Hat");					// I mean c'mon
			inventory.addHead(hat);

			Item * whip = new Item("Whip");					// Obviously
			inventory.addHead(whip);


			// Generate Board ------------------------------------------------------
			// Define size, which can be arbitrarily changed with minimal code change
			int rows = 20;
			int cols = 7;

			// Start fresh
			menu.clear();

			Space*** array = new Space ** [rows];           // An array of pointers pointing to arrays of Space pointers!! Whaaaa
															// 10 Rows, 5 columns
			for(int i = 0; i < rows; i++)
			{
				array[i] = new Space*[cols];
			}

			// Fill Board With Spaces
			for (int i = 0; i < rows; ++i)
			{
				for( int j = 0 ; j < cols; ++j)
				{
					if ( i == 4 || i == 5)					// Row 4 and 5 is the {{{CAVERNOUS ABYSS}}}
					{
						array[i][j] = new HoleSpace;
					}

					else if (i == 1 && j == 3)				// Idol space is a special rockspace
					{
						array[i][j] = new RockSpace;
					}

					else if (i == 1 && j == 4 || i == 1 && j == 2 || i == 0 && j == 3)				// Surrounding idol spaces are Rocks for aesthetic purposes
					{
						array[i][j] = new RockSpace;
					}

					else if (i == 2 && j == 3)				// Space in front of the Idol should be defined or it could be sealed off randomly
					{
						array[i][j] = new BlankSpace;
					}
					else if (i == 19 && j == 3)				// Space in front of entry/exit should not be a rock, that's a fire hazard
					{
						array[i][j] = new BlankSpace;
					}
					else
					{
						int roll = menu.roll(100);			// Roll for all other spaces
						if (roll > 85)
						{
							array[i][j] = new TrapSpace;	// 14% chance a space is a trap
						}

						else if (roll > 70)
						{
							array[i][j] = new RockSpace;	// 15% chance to be a rock
						}

						else
						{
							array[i][j] = new BlankSpace;	// Otherwise just a plain 'ol space
						}
					}
					
				}
			}

			// Set All Four Space Pointers within Each Space
			for (int i = 0; i < rows; ++i)
			{
				for( int j = 0 ; j < cols; ++j)
				{
					Space * temp = array[i][j];

					// Set Up
					if (i == 0)		// Upper edge
					{
						temp->setUp(nullptr);
					}

					else
					{
						temp->setUp(array[i - 1][j]);
					}

					// Set Down
					if (i == rows - 1)		// Lower edge
					{
						temp->setDown(nullptr);
					}

					else
					{
						temp->setDown(array[i + 1][j]);
					}

					// Set Right
					if (j == cols - 1)					// Edge right
					{
						temp->setRight(nullptr);
					}

					else
					{
						temp->setRight(array[i][j + 1]);	
					}

					// Set Left
					if(j == 0)							// Edge Left
					{
						temp->setLeft(nullptr);
					}

					else
					{
						temp->setLeft(array[i][j - 1]);
					}
				}
			}

			// Print manual / Print Board / UI --------------------------->>>

			menu.print(22);	// Manual

			cout << "   Indiana Jones\n";
			cout << "   HP: " << Jones.getHP();
			inventory.display();	// Familiarize user with items
			cout << "\n\n\n";

			// Board
			cout <<     "                                       _________\n";  // Formatting
			for ( int i = 0 ; i < rows ; ++ i )
			{
				cout << "                                       |";				// More formatting
				for(int j = 0 ; j < cols ; ++j)
				{
					Space * temp = array[i][j];

					if (i == Jones.getYpos() && j == Jones.getXpos())			// Start Position defined in Indiana class
					{
						cout << "O";
					}

					else
					{

						if (temp->getType() == 'B')			// Blank space is an apostrophe
						{
							cout << '\'';
						}

						else if (temp->getType() == 'H')	// Hole is a [space]
						{
							cout << ' ';
						}

						else if (temp->getType() == 'R')	// Rocks are X's
						{
							if (i == 1 && j == 3)
							{
								if(!hasIdol)
								{
									cout << 'I';			// Idol space is a non-default rock space
								}
								else
								{
									cout << 'X';
								}
							}

							else 
							{
								cout << 'X';
							}
						}

						else
						{
							cout << '\'';
						}
					}
				}
				cout << "|";
				cout << '\n';
			}
			cout <<     "                                       ---| |---\n\n";
			cout << " >> ";
			// <<----------------------------------------

			Space * currentSpace;

			while(!gameOver)
			{
				direction = ' ';
				validInput = false;
				currentSpace = array[Jones.getYpos()][Jones.getXpos()];

				// cout << "\nCurrentSpace\n   up: " << currentSpace->getUp() << "\n   down: " << currentSpace->getDown() << "\n   right: " << currentSpace->getRight() << "\n   left: " << currentSpace->getLeft() << "\n";

				while(!validInput)
				{	validInput = Jones.validateDirection();	}

				direction = Jones.getDirection();

				// clear Screen if not pickin an item..
				if (direction != 'i')
				{
					menu.clear();
				}

				// If player wants to move upwards..
				if (direction == 'w')
				{
					if(currentSpace->getUp() != nullptr)		// Ensure player is not on border space
					{
						Space * temp = currentSpace->getUp();
						if (temp->getType() == 'R')
						{
							menu.print(8);						// "A Rock is in your way!"
						}

						else
						{
							Jones.setYpos(Jones.getYpos() - 1);		// Set the new Y-coordinate position based on the current position
						}
					}

					else
					{
						menu.print(2);							// "A wall is in the way .. "
					}

					if(Jones.getYpos() == 6)					// Print a message if the cavernous pit is in your path
					{
						menu.print(3);
					}
				}

				if (direction == 's')
				{
					if (Jones.getXpos() == 3 && Jones.getYpos() == 19 && !hasIdol)		// Exit/win space needs the idol
					{
						menu.print(12);
					}

					else if (Jones.getXpos() == 3 && Jones.getYpos() == 19 && hasIdol)	// You win if you've got the idol
					{
						gameOver = true;
						wins	 = true;
					}

					else if (currentSpace->getDown() != nullptr)
					{
						Space * temp = currentSpace->getDown();
						if (temp->getType() == 'R')					// Can't move into rocks unless you swing onto them with your whip from across the cavern
						{
							menu.print(8);
						}
						else
						{
							Jones.setYpos(Jones.getYpos() + 1);
						}
					}

					else
					{
						menu.print(2);		// walked into a wall -_-
					}

					if(Jones.getYpos() == 3)					// Print a warning if the cavernous abyss is in your path
					{
						menu.print(3);
					}
				}

				if (direction == 'd')
				{
					if(currentSpace->getRight() != nullptr)
					{	
						Space * temp = currentSpace->getRight();	// No rock spaces!
						if (temp->getType() == 'R')
						{
							menu.print(8);
						}
						else
						{
							Jones.setXpos(Jones.getXpos() + 1);
						}
					}
					else
					{
						menu.print(2);
					}
				}

				if (direction == 'a')
				{
					Space * temp = currentSpace->getLeft();
					if(currentSpace->getLeft() != nullptr)
					{	
						if(temp->getType() == 'R')
						{
							menu.print(8);
						}
						else
						{
							Jones.setXpos(Jones.getXpos() - 1);
						}
					}
					else
					{
						menu.print(2);
					}
				}

				if (Jones.getXpos() == 3 && Jones.getYpos() == 2)
				{
					menu.print(9);
				}

				if (direction == 'i') // items!
				{
					if(!hasIdol)			// For the idol message
					{
						inventory.display();				// Show inventory
						cout << "      6) Do nothing\n";
						validInput = false;

						while(!validInput)
						{	
							menu.print(5);
							validInput = menu.validate(1, 6);	// Prompt user for item use
						}

						// clear screen after choosing item
						menu.clear();

						if (menu.getChoice() == 1)				// Whip scenarios
						{
							if (Jones.getYpos() == 6)			// Traverse the cavernous abyss
							{
								Jones.setYpos(3);
								menu.print(6);
								across = true;
							}

							else if (Jones.getYpos() == 3)		// Return
							{
								Jones.setYpos(6);
								menu.print(6);
								across = false;
							}

							else
							{
								menu.print(7);
							}
						}

						if (menu.getChoice() == 2)				// Hat scenarios
						{
							if (!straightHat)
							{
								menu.print(10);
								straightHat = true;
							}
							else
							{
								menu.print(11);
							}
						}

						if (menu.getChoice() == 3)				// Bottled Water scenarios
						{
							if(!drankWater)
							{
								menu.print(14);			
								Jones.setHP(Jones.getHP() + 10);
								drankWater = true;
							}
							else
							{
								menu.print(15);
							}
						}
						
						if (menu.getChoice() == 4)				// Trusty Sidearm scenarios
						{
							menu.print(16);
						}

						if (menu.getChoice() == 5)				// Bag of Sand used to get the idol
						{
							if(Jones.getXpos() == 3 && Jones.getYpos() == 2)	// If on Idol space..
							{
								menu.print(17);

								Item * idol = new Item("THE GOLDEN IDOL");		// Add it to the inventory
								inventory.addHead(idol);
								inventory.removeTail();							// Remove bag of sand from inventory

								hasIdol = true;									// Game-winning bool

							}
							else
							{
								menu.print(18);				// Otherwise feel the weight of the bag
							}
						}
					}

					else
					{
						inventory.display();
						cout << "      6) Do nothing\n";
						validInput = false;

						while(!validInput)
						{	
							menu.print(5);
							validInput = menu.validate(1, 6);	
						}

						// clear screen after choosing item
						menu.clear();

						if (menu.getChoice() == 1)				// Golden Idol
						{
							menu.print(19);
						}

						if (menu.getChoice() == 2)				// Whip scenarios
						{
							if (Jones.getYpos() == 6)			// Traverse the cavernous abyss
							{
								Jones.setYpos(3);
								menu.print(6);
								across = true;
							}

							else if (Jones.getYpos() == 3)		// Return
							{
								Jones.setYpos(6);
								menu.print(6);
								across = false;
							}

							else
							{
								menu.print(7);
							}
						}

						if (menu.getChoice() == 3)				// Hat scenarios
						{
							if (!straightHat)
							{
								menu.print(10);
								straightHat = true;
							}
							else
							{
								menu.print(11);
							}
						}

						if (menu.getChoice() == 4)				// Bottled Water scenarios
						{
							if(!drankWater)
							{
								menu.print(14);			
								Jones.setHP(Jones.getHP() + 10);
								drankWater = true;
							}
							else
							{
								menu.print(15);
							}
						}
						
						if (menu.getChoice() == 5)				// Trusty Sidearm scenarios
						{
							menu.print(16);
						}
					}
				}

				// Update Indi's position
				currentSpace = array[Jones.getYpos()][Jones.getXpos()];

				if (currentSpace->getType() == 'T')		// A trap!
				{
					int roll = menu.roll(8);			// Rolls 1d8 for damage
					menu.print(21);
					Jones.setHP(Jones.getHP() - roll);
					cout << "   He has taken " << roll << " points of damage!\n\n"; // print to screen
				}

				if (direction == 'X')
				{
					gameOver = true;
				}

				// If Indi walks into the carvernous pit..
				if (currentSpace->getType() == 'H')
				{
					if(!across)		// Change teleport point depending on whether he's already crossed the abyss
					{
						menu.print(4);
						Jones.setXpos(3);		// Define Indy's new position
						Jones.setYpos(19);
						Jones.setHP(Jones.getHP() - 2);
						currentSpace = array[Jones.getYpos()][Jones.getXpos()];
					}

					else			// If he hasn't crossed the abyss..
					{
						menu.print(4);
						Jones.setXpos(3);
						Jones.setYpos(2);
						Jones.setHP(Jones.getHP() - 2);
						currentSpace = array[Jones.getYpos()][Jones.getXpos()];
					}
				}

				// Print Board Again-------------------------------------------->>>

				cout << "   Indiana Jones\n";
				cout << "   HP: " << Jones.getHP();
				// inventory.display(); 
				cout << "\n   Items: [i]->[ENTER]";
				cout << "\n\n\n";

				cout <<     "                                       _________\n";
				for ( int i = 0 ; i < rows ; ++ i )
				{
					cout << "                                       |";
					for(int j = 0 ; j < cols ; ++j)
					{
						Space * temp = array[i][j];

						if (i == Jones.getYpos() && j == Jones.getXpos())
						{
							cout << "O";
						}

						else
						{

							if (temp->getType() == 'B')
							{
								cout << '\'';
							}

							else if (temp->getType() == 'H')
							{
								cout << ' ';
							}

							else if (temp->getType() == 'R')
							{
								if (i == 1 && j == 3)
								{
									if(!hasIdol)
									{
										cout << 'I';
									}
									else
									{
										cout << 'X';
									}
								}

								else 
								{
									cout << 'X';
								}
							}

							else
							{
								cout << '\'';
							}
						}
					}
					cout << "|";
					cout << '\n';
				}
				cout <<     "                                       ---| |---\n\n";
				cout << " >> ";
				// <<------------------------------------------------------

				if(Jones.getHP() <=0)	// If that boy be died
				{
					menu.clear();
					menu.print(13);
					gameOver = true;	// bummerrr
				}

			} // gameOver = true

			if(wins)					// oh hey congrats
			{
				quit = false;		
				menu.setChoice(0);
				menu.clear();
				menu.print(20);			
			}

			// Free ALL enslaved blocks, viva la revolucion
			for (int i = 0; i < rows; ++i)
			{
				for( int j = 0 ; j < cols; ++j)
				{
					Space * trash = array[i][j];
					delete trash;
				}
			}

			// Free all the Items as well
			for( int i = 0 ; i < rows ; i ++ )
			{
				delete [] array[i];
			}
  			delete [] array;

			for ( int i = 0 ; i < 10 ; i++)
			{
				inventory.removeHead();
			}
		}

		// Quit
		if(menu.getChoice() == 2)
		{
			quit = true;
			cout << "\n\n\t\tThx4playing!\n\n";
		}
	}
}