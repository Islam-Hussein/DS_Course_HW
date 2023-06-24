#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

class Vector
{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity; 

public:
    Vector(int size);

    int get(int idx);

    void set(int idx, int val);

    void push_back(int val);

    void print();

    int find(int val);

    void expand_capacity();


    void insert(int idx , int val);

    int get_front();

    int get_back();

    void right_rotation();

    void left_rotation();

    void right_rotation_with_steps(int n);

    void left_rotation_with_steps(int n);

    int pop(int idx);


    int find_transposition(int val);


    ~Vector();
};

#endif