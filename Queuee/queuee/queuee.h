#ifndef QUEUEE_H_
#define QUEUEE_H_
#include <iostream>
#include "../LinkedList/LinkedList.h"


class Queuee
{
private: 
    LinkedList list;

public:

    void enqueue(int value);

    int dequeue(void);

    void display(void);

    bool is_empty(void);


};


#endif