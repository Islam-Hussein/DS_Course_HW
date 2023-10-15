#include "stack.h"


bool stack::is_full(void)
{
    if(top == size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::is_empty(void)
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void stack::display(void)
{
    if(this->stack::is_empty())
    {
        std::cout << "The Stack is empty!\n";
        return;
    }

    for(int i = top ; i >= 0 ; i--)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n"; 
}

void stack::push(int x)
{
    assert(!this->is_full());
    array[++top] = x;
}

int stack::pop(void)
{
    assert(!this->is_empty());
    return array[top--];
}


int stack::peek(void)
{
    assert(!this->is_empty());
    return array[top];
}