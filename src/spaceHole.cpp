/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Hole space affects the player by 
 *  transporting the player to a new space and
 *  dealing damage in Game()
 ***********************************************/


#include "spaceHole.hpp"

HoleSpace::HoleSpace()
{

}

/***********************************
  *             action()
  * 
  *  No other action, returns 0
************************************/
int HoleSpace::action()
{
    return 0;
}

/***********************************
  *             getType()
  * 
  *  returns 'H'
************************************/
char HoleSpace::getType()
{
    // 'H' for 'hole'
    return 'H';
}