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

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Constructor runs program
Game::Game()
{
	// Initalize variables needed for menu
	bool validInput = false;
	bool quit 		= false;
	// Seed rand to make a new board each playthrough
	srand(time(0));
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
			// Summon the protagonist
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

            // Generate Indy's inventory and equip him with his classic set
			Link inventory; 

			Item * sandbag = new Item("Bag of Sand");		// Mandatory Item
			inventory.addHead(sandbag);

			Item * sidearm = new Item("Trusty Sidearm");	// No real use in a cave but whatever
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
            // An array of pointers pointing to arrays of Space pointers!! Whaaaa..
			Space*** array = new Space ** [rows];

			for(int i = 0; i < rows; i++)
			{
				array[i] = new Space*[cols];
			}

			// Fill Board With Spaces
			for (int i = 0; i < rows; ++i)
			{
				for( int j = 0 ; j < cols; ++j)
				{
	                // Row 4 and 5 is the {{{CAVERNOUS ABYSS}}}
					if ( i == 4 || i == 5)
					{
						array[i][j] = new HoleSpace;
					}

                    // Idol space is a special rockspace
					else if (i == 1 && j == 3)
					{
						array[i][j] = new RockSpace;
					}
                    // Surrounding idol spaces are Rocks for aesthetic purposes
					else if ((i == 1 && j == 4) || (i == 1 && j == 2) || (i == 0 && j == 3))
					{
						array[i][j] = new RockSpace;
					}
                    // Space in front of the Idol should be defined or it could be sealed off randomly
					else if (i == 2 && j == 3)
					{
						array[i][j] = new BlankSpace;
					}
                    // Space in front of entry/exit should not be a rock, that's a fire hazard
					else if (i == 19 && j == 3)
					{
						array[i][j] = new BlankSpace;
					}
					else
					{
                        // Roll for all other spaces
						int roll = menu.roll(100);
						if (roll > 85)
						{
                            // 14% chance a space is a trap
							array[i][j] = new TrapSpace;
						}

						else if (roll > 70)
						{
                            // 15% chance to be a rock
							array[i][j] = new RockSpace;
						}

						else
						{
                            // Otherwise just a plain 'ol space
							array[i][j] = new BlankSpace;	
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
                // More formatting
				cout << "                                       |";
				for(int j = 0 ; j < cols ; ++j)
				{
					Space * temp = array[i][j];

                    // Start Position defined in Indiana class
					if (i == Jones.getYpos() && j == Jones.getXpos())
					{
						cout << "O";
					}

					else
					{
                        // Blank space is an apostrophe
						if (temp->getType() == 'B')
						{
							cout << '\'';
						}
                        // Hole is a [space]
						else if (temp->getType() == 'H')	
						{
							cout << ' ';
						}
                        // Rocks are X's
						else if (temp->getType() == 'R')	
						{
							if (i == 1 && j == 3)
							{
								if(!hasIdol)
								{
                                    // Idol space is a non-default rock space
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
			// <<----------------------------------------

			Space * currentSpace;

			while(!gameOver)
			{
				direction = ' ';
				validInput = false;
				currentSpace = array[Jones.getYpos()][Jones.getXpos()];

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
		            // Ensure player is not on border space
					if(currentSpace->getUp() != nullptr)
					{
						Space * temp = currentSpace->getUp();
						if (temp->getType() == 'R')
						{
                            // "A Rock is in your way!"
							menu.print(8);
						}

						else
						{
		                    // Set the new Y-coordinate position based on the current position
							Jones.setYpos(Jones.getYpos() - 1);
						}
					}

					else
					{
                        // "A wall is in the way .. "
						menu.print(2);
					}

                    // Print a message if the cavernous pit is in your path
					if(Jones.getYpos() == 6)
					{
						menu.print(3);
					}
				}

				if (direction == 's')
				{		
                    // Exit/win space needs the idol
					if (Jones.getXpos() == 3 && Jones.getYpos() == 19 && !hasIdol)
					{
						menu.print(12);
					}

	                // You win if you've got the idol
					else if (Jones.getXpos() == 3 && Jones.getYpos() == 19 && hasIdol)
					{
						gameOver = true;
						wins	 = true;
					}

					else if (currentSpace->getDown() != nullptr)
					{
						Space * temp = currentSpace->getDown();
                        // Can't move into rocks unless you swing onto them with your whip from across the cavern
						if (temp->getType() == 'R')
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
		                // walked into a wall -_-
						menu.print(2);
					}
					// Print a warning if the cavernous abyss is in your path
					if(Jones.getYpos() == 3)
					{
						menu.print(3);
					}
				}

				if (direction == 'd')
				{
					if(currentSpace->getRight() != nullptr)
					{	
                        // No rock spaces!
						Space * temp = currentSpace->getRight();
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
                // items!
				if (direction == 'i') 
				{
			        // For the idol message
					if(!hasIdol)
					{
                        // Show inventory
						inventory.display();
						cout << "      6) Do nothing\n";
						validInput = false;

						while(!validInput)
						{	
							menu.print(5);
	                        // Prompt user for item use
							validInput = menu.validate(1, 6);
						}

						// clear screen after choosing item
						menu.clear();

                    	// Whip scenarios
						if (menu.getChoice() == 1)
						{
			                // Traverse the cavernous abyss
							if (Jones.getYpos() == 6)
							{
								Jones.setYpos(3);
								menu.print(6);
								across = true;
							}

		                    // Return
							else if (Jones.getYpos() == 3)
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

				        // Hat scenarios
						if (menu.getChoice() == 2)
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

                        // Bottled Water scenarios
						if (menu.getChoice() == 3)
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

                        // Trusty Sidearm scenarios
						if (menu.getChoice() == 4)
						{
							menu.print(16);
						}

				        // Bag of Sand used to get the idol
						if (menu.getChoice() == 5)
						{
	                        // If on Idol space..
							if(Jones.getXpos() == 3 && Jones.getYpos() == 2)
							{
								menu.print(17);
		                        // Add it to the inventory
								Item * idol = new Item("THE GOLDEN IDOL");
								inventory.addHead(idol);
                                // Remove bag of sand from inventory
								inventory.removeTail();
                                // Game-winning bool
								hasIdol = true;

							}
							else
							{
                                // Otherwise feel the weight of the bag
								menu.print(18);				
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

                        // Golden Idol
						if (menu.getChoice() == 1)
						{
							menu.print(19);
						}

                        // Whip scenarios
						if (menu.getChoice() == 2)
						{
                            // Traverse the cavernous abyss
							if (Jones.getYpos() == 6)
							{
								Jones.setYpos(3);
								menu.print(6);
								across = true;
							}
		                    // Return
							else if (Jones.getYpos() == 3)
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
                        // Hat scenarios
						if (menu.getChoice() == 3)
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
				        // Bottled Water scenarios
						if (menu.getChoice() == 4)
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
						// Trusty Sidearm scenarios
						if (menu.getChoice() == 5)
						{
							menu.print(16);
						}
					}
				}

				// Update Indi's position
				currentSpace = array[Jones.getYpos()][Jones.getXpos()];
		        // A trap!
				if (currentSpace->getType() == 'T')
				{
                    // Rolls 1d8 for damage
					int roll = menu.roll(8);
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
                    // Change teleport point depending on whether he's already crossed the abyss
					if(!across)
					{
						menu.print(4);
		                // Define Indy's new position
						Jones.setXpos(3);
						Jones.setYpos(19);
						Jones.setHP(Jones.getHP() - 2);
						currentSpace = array[Jones.getYpos()][Jones.getXpos()];
					}
			        // If he hasn't crossed the abyss..
					else
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
            //getchar();
            menu.clear();
			cout << "\n\n\t\tThx4playing! [Exited]\n\n";
		}
	}
}
