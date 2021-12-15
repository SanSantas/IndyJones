/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: A rock space cannot be walked
 *  into. It is a barrier in Game()
 ***********************************************/


#include "space.hpp"
#include <string>
using std::string;

#ifndef ROCKSPACE_HPP
#define ROCKSPACE_HPP

class RockSpace : public Space
{
private:

public:
	
    RockSpace();
    virtual ~RockSpace();

    int action();
    char getType();
};

#endif
