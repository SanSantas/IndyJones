/************************************************
 * Author:	Andre Ortega
 * Date:	12/9/2019
 * Description: Indiana Jones!
 ***********************************************/

#include <string>
using std::string;

#ifndef INDIANA_HPP
#define INDIANA_HPP

class Indiana
{
private:

    // Hit points, XY position, and user-requested direction
    int HP;
    int Xpos;
    int Ypos;
    char direction;

public:

	Indiana();

    void setHP(int);
    int getHP();

    // These determine and store Indy's position on the grid
    void setXpos(int);
    void setYpos(int);
    int getXpos();
    int getYpos();

    // Choose a direction for Indiana
    void setDirection(char);

    // Get the direction of Indiana
    char getDirection();

    // Validate char input
    bool validateDirection();

};

#endif