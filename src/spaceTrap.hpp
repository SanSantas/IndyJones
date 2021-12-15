/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Trap! This special space deals
 *  damage to indie in game()
 ***********************************************/


#include "space.hpp"
#include <string>
using std::string;

#ifndef TRAPSPACE_HPP
#define TRAPSPACE_HPP

class TrapSpace : public Space
{
private:

public:
	
    TrapSpace();

    int action();
    char getType();
};

#endif