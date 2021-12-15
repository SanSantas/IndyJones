/*******************************************************************
 ** Author:       Andre Ortega
 ** Date:         11/7/2019
 ** Description:  Link header file defines methods needed to alter
            the linked list properly
*******************************************************************/

#include "link.hpp"
#include "item.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

//Constructor sets to nullptr
Link::Link()
{
    head = nullptr;
    tail = nullptr;
}

//Destructor removes all allocated linked nodes at termination
Link::~Link()
{
    Node * nodePtr = head;
    while(nodePtr != nullptr)
    {
        Node * trash = nodePtr;
        nodePtr = nodePtr->next;
        delete trash;
    }
}


/***********************************
 *          Add Head
 * 
 * Takes one int and adds it to the 
 * head of the list, while keeping
 * pointers updated
 **********************************/

void Link::addHead(Item * number)
{
    //If the list is empty, point head and tail to new head
    if (head == nullptr)
    {
        head = new Node(number);
        tail = head;
    }

    //Normal case
    else
    {
        //Duplicate head
        Node *nodePtr = head;

        //Create new head
        head = new Node(number);

        //Point new head to old head        
        head->next = nodePtr;

        //Point old head to new head
        nodePtr->prev = head;

        //Find the tail ( for when second Node is created )
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        //Set the tail
        tail = nodePtr;
    }

}


/***********************************
 *          Add Tail
 * 
 * Takes one int and adds it to the 
 * tail of the list, while keeping
 * pointers updated
 **********************************/

void Link::addTail(Item * number)
{
    //Point head to tail if new Node is first Node
    if (tail == nullptr)
    {
        tail = new Node(number);
        head = tail;
    }

    else
    {
        //Duplicate tail Node
        Node *nodePtr = tail;

        //Create new tail
        tail = new Node(number);

        //Point tail to previous Node
        tail->prev = nodePtr;

        //Point previous tail to new tail
        nodePtr->next = tail;

        //Find head ( Useful when second node is added by tail )
        while (nodePtr->prev != nullptr)
        {
            nodePtr = nodePtr->prev;
        }

        //Set head
        head = nodePtr;
    }
    
}

/***********************************
 *          Remove Head
 * 
 * Deletes the head and updates the 
 * pointers 
 **********************************/

void Link::removeHead()
{

    //Check if list is empty
    if(!head)
    {
        //cout << "\n   The list is empty.\n";
    }

    else
    {
        //Duplicate head node
        Node *nodePtr = head;

        delete head->value;

        //Set head/tail to null if only Node
        if (head->next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }

        //Set new head and update next pointer
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        
        //Delete detached temporary nodePtr
        delete nodePtr;
    }
}

/***********************************
 *          Remove Tail
 * 
 * Deletes the tail and updates the 
 * pointers 
 **********************************/

void Link::removeTail()
{
    //Code is repeated from removeHead()
    if(!tail)
    {
        cout << "\n   The list is empty\n";
    }
    else
    {
        Node *nodePtr = tail;

        delete tail->value;


        if (tail->prev == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete nodePtr;
    }
}

/***********************************
 *          Display
 * 
 * Displays Nodes Sequentially
 **********************************/
void Link::display()
{
    Node *nodePtr = head;
    cout << "\n   Indi's Inventory: \n\n";
    int i = 1;
    while(nodePtr)
    {
        cout << "      " << i << ") " << nodePtr->value->getName() << "\n";
        nodePtr = nodePtr->next;
        i++;
    }

    cout << endl;
}

