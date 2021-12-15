/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Header file for space declaration
 * 		and implementation, which is contains four
 *      pointers elading to adjacent spaces, as 
 *      well as a pure virtual action function
 ***********************************************/

#include <string>
using std::string;

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
protected:

    // Pointers to adjacent spaces
    Space * up;
    Space * down;
    Space * left;
    Space * right; 

public:

	Space();
    virtual ~Space();

    // Functions return pointers to adjacent spaces
    Space * getUp();
    Space * getDown();
    Space * getLeft();
    Space * getRight();

    // Set functions accepting space pointers to adjacent spaces
    void setUp(Space*);
    void setDown(Space*);
    void setLeft(Space*);
    void setRight(Space*);

    // Virtual functions for getting specific space type and action
    virtual int action() =0;
    virtual char getType() =0;
};

#endif
