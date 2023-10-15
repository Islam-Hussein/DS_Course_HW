#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cassert>

class stack
{
private:
    int size { };
    int top { };
    int * array { };


public:
    stack(int size) : size(size) , top{-1}
    {
        array = new int[size];
    }


    bool is_full(void);

    bool is_empty(void);

    void display(void);

    void push(int x);

    int pop(void);

    int peek(void);

};




#endif