//
//  main.cpp
//  Linked List
//
//  Created by Brett Markowitz on 7/19/17.
//  Copyright © 2017 Brett Markowitz. All rights reserved.
//

#include <iostream>
using namespace std;

//node struct
struct node {
    int data;
    struct node* next;
};
node* start = nullptr;

//function prototypes
struct node* getNode();
void createList(int);

void insertAtBeg();
void insertAtEnd();
void insertAtMid();

void deleteAtBeg();
void deleteAtEnd();
void deleteAtMid();

int countNode(node*);
void displayNode(node*&);

//main function
int main() {
    
    int choice;
    
    cout << "Enter the number of nodes you'd like in the list: ";
    cin >> choice;
    
    createList(choice);
    
    cout << "Here is the list you created:\n";
    
    displayNode(start);
    
    deleteAtMid();
    
    displayNode(start);
    
    insertAtMid();
    
    displayNode(start);

    return 0;
}

/* getNode():
 - Creates a pointer to a node
 - allocates the space for a node and assigns the address to newNode pointer
 - asks the user to insert a number into the node
 - initializes the node's next pointer to null
 - returns the address of the created node 
 */

struct node* getNode()
{
    node* newNode;
    newNode = new node;
    cout << "Enter a number to store in the node: ";
    cin >> newNode->data;
    newNode->next = nullptr;
    
    return newNode;
}

/* createList():
 - Creates three variables: a variable for a for loop (which goes from 0 to one less than length user enters) and two node pointers
 - For loop creates a new node and stores its address in newNode. 
 - Then, if the passed in start node is null, it is set to point to the just-created node
 - Else, a temp node is set to start (an address since list isn't empty) and the while loop 
 stops when it hits a next pointer that's null (end of the list)
 - Temp->next is then set to the new node (at end of the list)
 - Whatever the situation (empty list or already populated list), start node is returned
 */

void createList(int a)
{
    int i;
    node* newNode;
    node* temp;
    for(i = 0; i < a; i++)
    {
        newNode = getNode();
        if (start == nullptr)
        {
            start = newNode;
        }
        else {
            temp = start;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

}


/* insertAtBeg():
 - Creates a node pointer and stores a new node's address in that pointer
 - If the list is empty, the start points to that node
 - If the list is already populated with nodes, newNode's next pointer points 
 to the current start, then start points to newNode
 */

void insertAtBeg()
{
    node* newNode;
    newNode = getNode();
    if(start == nullptr)
    {
        start = newNode;
    }
    else
    {
        newNode->next = start;
        start = newNode;
    }
}


/* insertAtEnd():
 - Creates two node pointers and creates a node for one of them
 - If the list is empty, the start points to that node
 - If the list is already populated with nodes, temp holds the start address and 
 moves through the list, stopping at the last node
 - The last node's next pointer is set to point to the newly-created node
 */
void insertAtEnd()
{
    node* newNode;
    node* temp;
    newNode = getNode();
    if(start == nullptr)
    {
        start = newNode;
    }
    else
    {
        temp = start;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}



/* insertAtMid():
 - Creates three node pointers + position, nodectr, and ctr = 1 variables
 - newNode holds the address of a newly-created node
 - The user is asked where in the list they want to add that node and the input is stored in pos
 - A separate countNode function counts the nodes in the list
 - If pos is between 1 and the number returned by nodectr, temp and prev are set to the same position as start
 - As long as ctr is less than the position entered by the user, prev (only after the first loop through) and temp advance
 and ctr is incremented by 1.
 - When the the desired position is reached, prev->next points to the new node, and the new node points to temp
 - Else, the user is told the position is not in the middle of the list
 */
void insertAtMid()
{
    node* newNode;
    node* temp;
    node* prev;
    int pos;
    int nodectr;
    int ctr = 1;
    newNode = getNode();
    cout << "Enter the position to add this node at: ";
    cin >> pos;
    nodectr = countNode(start);
    if(pos > 1 && pos < nodectr)
    {
        temp = start;
        prev = start;
        while (ctr < pos)
        {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newNode;
        newNode->next = temp;
    }
    else
    {
        cout << "The position you entered is not in the middle of the list. \n";
    }
}



/* deleteAtBeg():
 - Creates node pointer
 - If start pointer is null, user is notified that the list is empty
 - Else, temp is given the start address, and start moves to the next node using the temp node
 - Temp is deleted and user is notified
 */

void deleteAtBeg()
{
    node* temp;
    if(start == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
    
    else if(start->next == nullptr)
    {
        temp = start;
        start = nullptr;
        delete temp;
        cout << "The node at the beginning of the list has been deleted.\n";
        return;
    }
    
    else
    {
        temp = start;
        start = temp->next;
        delete temp;
        cout << "The node at the beginning of the list has been deleted.\n";
    }
}



/* deleteAtEnd():
 - Creates two node pointers, temp and prev
 - If the start pointer is null, the user is notified that the list is empty and the function immediately returns
 - Else, temp and prev are initialized to the start pointer's contents, and they both move forward (prev one node behind) in the list
 - Then, the second to last node's next pointer is made null, and temp (which is at the old final node) is deleted
 */
void deleteAtEnd()
{
    node* temp;
    node* prev;
    if(start == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
    
    else if(start->next == nullptr)
    {
        temp = start;
        start = nullptr;
        delete temp;
        cout << "The node at the beginning of the list has been deleted.\n";
        return;
        
    }
    else
    {
        temp = start;
        prev = start;
        while(temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
        cout << "The node at the end of the list has been deleted.\n";
    }
}



/* deleteAtMid():
 - Creates two node pointers and three variables: position, ctr = 1, and nodectr
 - If the start pointer is null, the user is notified the list is empty and the function immediately returns
 - Else, the user is asked which node they want to delete, which is stored in pos
 - countNode counts the nodes in the list and stores the number in nodectr
 - If pos is greater than the number of nodes in the list, the user is notified and the function immediately returns
 - Else if the pos is between 1 and nodectr, temp and prev pointers are set to the start of the list
 - As long as ctr is less than pos, prev and temp advance (prev is 1 behind temp) and ctr is incremented
 - Else, the user is told the position they entered doesn't exist in the list
 - Once the desired position is reached, prev->next is set to temp->next and temp is deleted...user is notified.
 */
void deleteAtMid()
{
    int ctr = 1;
    int pos;
    int nodectr;
    node* temp;
    node* prev;
    if(start == nullptr)
    {
        cout << "The list is empty.";
        return;
    }
    else
    {
        cout << "Enter the position you want to delete: ";
        cin >> pos;
        nodectr = countNode(start);
        if(pos > nodectr)
        {
            cout << "The postion you entered does not exist in the list. \n";
            return;
        }
        else if(pos > 1 && pos < nodectr)
        {
            temp = start;
            prev = start;
            while(ctr < pos)
            {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
        }
        else {
            cout << "The postion you entered is not in the middle of list. \n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "The selected node has been deleted. \n";
    }
}


/* countNode():
 - Creates a node pointer and points it to the same node as start
 - Initializes a ctr variable to 0
 - If start is null, the user is notified and 0 is returned as the number of nodes in the list
 - Else, temp moves forward in the list 1 node at a time and counter is incremented by 1 each time until temp = null
 - The final value of ctr is returned
 */
int countNode(node* s)
{
    node* temp;
    temp = s;
    int ctr = 0;
    if(s == nullptr)
    {
        cout << "The list is empty.";
        return ctr;
    }
    else
    {
        while(temp != nullptr)
        {
            ctr += 1;
            temp = temp->next;
        }
    }
    return ctr;
}


/* displayNode():
 - Creates a node pointer and points it to the same node as start
 - If start is null, the user is notified and the function immediately returns
 - Else, temp moves forward in the list 1 node at a time and each node's data field is printed until temp = null
 */
void displayNode(node*& s)
{
    node* temp;
    temp = s;
    if(s == nullptr)
    {
        cout << "The list is empty.";
        return;
    }
    else
    {
        while(temp!= nullptr)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
}
