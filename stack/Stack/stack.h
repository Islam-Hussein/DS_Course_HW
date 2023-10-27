#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cassert>
#include <string>

#define     ARRAY_IMPLEMENTATION        0
#define     LINKEDLIST_IMPLEMENTATION   1


#if         ARRAY_IMPLEMENTATION    ==      1

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

    ~stack()
    {
        delete[] array;
    }


    bool is_full(void);

    bool is_empty(void);

    void display(void);

    void push(int x);

    int pop(void);

    int peek(void);

    int isEmpty();

    int isFull();


};
#endif

#if     LINKEDLIST_IMPLEMENTATION       ==      1

class stack
{
private:
    struct Node
    {
        int data { };
        Node * next { };
        Node (int data) : data(data) { }
    };

    Node * head { };

public:
    ~stack()
    {
        while(!isEmpty())
        {
            pop();
        }
    }

    int isEmpty(void);

    void push(int num);

    int pop(void);

    int peek(void);

    void display(void);



};

std::string infixToPostfix(std::string infix);

int precedence(char op);

#endif



#endif