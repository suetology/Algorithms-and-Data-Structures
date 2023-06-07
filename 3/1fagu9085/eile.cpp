#include "eile.h"
#include <iostream>
#include <stdlib.h>
	using namespace std;


Node* createQueue() {
    Node* front = NULL;
    return front;
}

int isEmpty(Node* front) {
    if (front == NULL)
        return 1;
    else
        return 0;
}

void enQueue(Node** front, int value) {
    Node* ptr = new Node();
    if (ptr == NULL) {
        exit(1);
    }
    ptr->data = value;
    ptr->link = NULL;

    if (isEmpty(*front)) {
        *front = ptr;
    } else {
        Node* rear = *front;
        while (rear->link != NULL) {
            rear = rear->link;
        }
        rear->link = ptr;
    }
}

int deQueue(Node** front) {
    int temp;
    if (isEmpty(*front)) {
        return -1;
    } else {
        Node* ptr = *front;
        temp = ptr->data;
        *front = (*front)->link;
        free(ptr);
        return temp;
    }
}

void makeEmpty(Node** front) {
  while (!isEmpty(*front)) {
    deQueue(front);
  }
}

void displayQueue(Node* front) {
  if (isEmpty(front))
    cout << "Queue is empty\n";
  else {
    Node* ptr = front;
    while (ptr != NULL) {
      cout << ptr->data << " ";
      ptr = ptr->link;
    }
    cout << endl;
  }
}

int showFront(Node* front) {
    if (isEmpty(front))
    {
        return -1;
    }
    else
    {
        return front->data;
    }
}

Node* cloneQueue(Node* front) {
    Node* new_front = NULL;
    Node* new_rear = NULL;

    Node* ptr = front;
    while (ptr != NULL) {
        Node* new_node = new Node();
        new_node->data = ptr->data;
        new_node->link = NULL;

        if (new_front == NULL) {
            new_front = new_node;
            new_rear = new_node;
        } else {
            new_rear->link = new_node;
            new_rear = new_node;
        }

        ptr = ptr->link;
    }

    return new_front;
}








