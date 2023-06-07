#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

struct Node
{
    int data;
    Node* link;
};

Node* createQueue();
int isEmpty(Node* front);
void enQueue(Node** front, int value);
int deQueue(Node** front);
int showFront(Node* front);
void displayQueue(Node* front);
void makeEmpty(Node** front);
Node* cloneQueue(Node* front);

#endif // QUEUE_H_INCLUDED
