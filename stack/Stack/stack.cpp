#include "stack.h"

#if         ARRAY_IMPLEMENTATION    ==      1

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

int stack::isEmpty()
{
    return top == -1;
}

int stack::isFull() 
{
    return top == size - 1;
}

#endif


#if     LINKEDLIST_IMPLEMENTATION       ==      1


void stack::push(int num)
{
    Node * item = new Node(num);
    item->next = head;
    head = item;
}

int stack::pop(void)
{
    assert(!stack::isEmpty());
    int element = head->data;
    Node * tmp = head;
    head = head->next;
    delete tmp;
    return element;
}


int stack::isEmpty(void)
{
    return (!head);
}

int stack::peek(void)
{
    assert(!stack::isEmpty());
    int element = head->data;

    return element;
}

void stack::display(void)
{
    assert(!isEmpty());
    std::cout << "Stack elements are : \n";


    Node * curr = head;
    while(curr)
    {
        std::cout << curr->data <<  " " ;

        curr = curr->next;
    }
    std::cout << "\n";
}

int precedence(char op)
{
    if((op == '+') || (op == '-'))
    {
        return 1;
    }

    if((op == '*') || (op == '/'))
    {
        return 2;
    }

    return 0;
}



std::string infixToPostfix(std::string infix)
{
    stack operators;
    std::string postfix;
    infix += '-';
    operators.push('#');


	for (int i = 0; i < (int) infix.size(); ++i) {
		if (isdigit(infix[i]))
			postfix += infix[i];
		else {
			while (precedence(operators.peek()) >= precedence(infix[i]))
				postfix += operators.pop();
			operators.push(infix[i]);
		}
	}

	return postfix;
}

#endif