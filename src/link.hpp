/*******************************************************************
 ** Author:       Andre Ortega
 ** Date:         11/7/2019
 ** Description:  Link header file declares objects needed to store 
        necessary variables and pointers
*******************************************************************/

#include "item.hpp"

#ifndef LINK_HPP
#define LINK_HPP

class Link
{
    protected:

        //Node contains a method to generate another node
        struct Node
        {
            Item * value;
            Node *next;
            Node *prev;

            //Constructor can be used to point to next/previous node upon declaration
            // Stores pointers to Item classes to be used in game
            Node(Item * value1, Node *prev1 = nullptr, Node *next1 = nullptr)
            {
                value = value1;
                next = next1;
                prev = prev1;
            }
        };

        //Class contains pointer to head and tail
        Node *head;
        Node *tail;

    public:
        Link();
        ~Link();
        void addHead(Item*);
        void addTail(Item*);
        void removeHead();
        void removeTail();
        void display();

};

#endif