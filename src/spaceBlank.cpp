/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Implementation for blank space.
 *  It doesn't do much. :/
 ***********************************************/


#include "spaceBlank.hpp"

/***********************************
  *             BlankSpace()
  * 
  *  It's blank it don't do nuthn
************************************/
BlankSpace::BlankSpace()
{
}

BlankSpace::~BlankSpace()
{
}
/***********************************
  *             Action()
  * 
  *  Still Blank, still nuthn
************************************/
int BlankSpace::action()
{
    return 0;
}

/***********************************
  *             getType()
  * 
  *  'B' means blank
************************************/
char BlankSpace::getType()
{
    return 'B';
}
