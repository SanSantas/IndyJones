/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Items!
 ***********************************************/

#include "item.hpp"
#include <iostream>

/**********************************
 * 			Item()
 * 
 * 	Accepts a string used to present
 * the user with their options
 *********************************/
Item::Item(string name)
{
    this->name = name;
}

/**********************************
 * 			   getName()
 * 
 * 	Returns the name of the item as
 * a string
 *********************************/
string Item::getName()
{
    return name;
}