/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: 
 ***********************************************/


#include "space.hpp"
#include <string>
using std::string;

#ifndef BLANKSPACE_HPP
#define BLANKSPACE_HPP

class BlankSpace : public Space
{
private:

public:
	
    // blank constructor
    BlankSpace();

    // No action
    int action();

    // Returns 'B'
    char getType();
};

#endif