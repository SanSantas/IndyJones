/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Items are used by the player to
 *  do certain tasks within the game. Their uses
 *  are defined in game.cpp
 ***********************************************/

#include <string>
using std::string;

#ifndef Item_HPP
#define Item_HPP

class Item
{
private:

    // Used for presentation of user options
    string name;

public:

	Item(string name);

    // Returns the item name
    string getName();

};

#endif