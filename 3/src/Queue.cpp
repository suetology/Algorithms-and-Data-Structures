#include "Queue.h"

Queue::Queue()
{
    node = createQueue();
}

Queue::Queue(const Queue& other)
{
	node = cloneQueue(other.node);
}

Queue::~Queue()
{
	MakeEmpty();
}

bool Queue::IsEmpty() const
{
	return isEmpty(node);
}

void Queue::Enqueue(int value)
{
	enQueue(&node, value);
}

int Queue::Dequeue()
{
	return deQueue(&node);
}

int Queue::GetFront() const
{
	return showFront(node);
}

void Queue::Display() const
{
	displayQueue(node);
}

void Queue::MakeEmpty()
{
	makeEmpty(&node);
}