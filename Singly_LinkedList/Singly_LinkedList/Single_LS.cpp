#include "Single_LS.h"

void LinkedList::Print_LS()
{
    for(Node* curr = head ; curr; curr = curr->next)
    {
        std::cout << curr->data << " ";
    }    
    std::cout<< "\n";
}

void LinkedList::Insert_end(int val)
{
    Node* item = new Node(val);

    if(!head)
    {
        head = tail = item;
    }
    else
    {
        tail->next = item;
        tail = item;
    }
    ++length;
}


int LinkedList::search(int val)
{
    int idx = 0;
    for(Node* cur = head ; cur; cur = cur->next , idx++)
    {
        if(cur->data == val)
        {
            return  idx; 
        }
    }
    return -1;
}

Node* LinkedList::get_nth(int n)
{
    int counter = 0;
    for(Node* curr = head; curr ; curr = curr->next)
    {
        if(++counter == n)
        {
            return curr;
        }
    }
    return nullptr;
}

