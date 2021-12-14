/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: 
 ***********************************************/


#include "space.hpp"
#include <string>
using std::string;

#ifndef HOLESPACE_HPP
#define HOLESPACE_HPP

class HoleSpace : public Space
{
private:

public:
	
    HoleSpace();

    int action();
    char getType();
};

#endif