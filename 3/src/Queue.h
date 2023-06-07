#pragma once

#include "eile.h"

class Queue 
{
private:
    Node* node;

public:
    Queue();
    Queue(const Queue& other);
    ~Queue();

    bool IsEmpty() const;
    void Enqueue(int value); 
    int Dequeue();
    int GetFront() const;
    void Display() const;
    void MakeEmpty();
};