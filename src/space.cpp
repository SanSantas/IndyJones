/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: 
 ***********************************************/

#include "space.hpp"

/***********************************
  *             Space()
  * 
  *     Constructor sets all to Null
  * to be defined in Game()
************************************/
Space::Space()
{
    up      = nullptr;
    down    = nullptr;
    right   = nullptr;
    left    = nullptr;
}
Space::~Space()
{
}

/***********************************
  *             getUp()
  * 
  *  Returns pointer to space above
************************************/
Space * Space::getUp()
{
    return up;
}
/***********************************
  *             getDown()
  * 
  *  Returns pointer to space below
************************************/
Space * Space::getDown()
{
    return down;
}

/***********************************
  *             getLeft()
  * 
  *  Returns pointer to space left
************************************/
Space * Space::getLeft()
{
    return left;
}

/***********************************
  *             getRight()
  * 
  *  Returns pointer to space right
************************************/
Space * Space::getRight()
{
    return right;
}
/***********************************
  *             setUp()
  * 
  *  Accepts pointer to space above
************************************/
void Space::setUp(Space* in)
{
    up = in;
}

/***********************************
  *             setDown()
  * 
  *  Accepts pointer to space below
************************************/
void Space::setDown(Space* in)
{
    down = in;
}

/***********************************
  *             setLeft()
  * 
  *  Accepts pointer to space left
************************************/
void Space::setLeft(Space* in)
{
    left = in;
}

/***********************************
  *             setUp()
  * 
  *  Accepts pointer to space left
************************************/
void Space::setRight(Space* in)
{
    right = in;
}
