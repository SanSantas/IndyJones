/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Implementation for inhereted 
 *      trap class from Space
 ***********************************************/


#include "spaceTrap.hpp"

TrapSpace::TrapSpace()
{
}

TrapSpace::~TrapSpace()
{
}

int TrapSpace::action()
{
    return 0;
}

/***********************************
  *             getType()
  * 
  *  Returns 'T' for 'Trap
************************************/
char TrapSpace::getType()
{
    return 'T';
}
