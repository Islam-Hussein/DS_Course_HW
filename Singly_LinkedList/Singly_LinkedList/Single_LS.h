#ifndef SINGLE_LS_H_
#define SINGLE_LS_H_

#include <iostream>

struct Node
{
    int data {};
    Node * next {};
    Node(int data) : data (data) {}
};

class LinkedList
{
private:
    Node * head{};
    Node * tail{};
    int length = 0;

public:
    void Print_LS();

    void Insert_end(int val);

    int search(int val);

    Node* get_nth(int n);



};

#endif