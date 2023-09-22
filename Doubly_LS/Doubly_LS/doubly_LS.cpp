#include "doubly_LS.h"

void link(Node * first , Node * second)
{
    if(first)
    {
        first->next = second;
    }
    if(second)
    {
        second->prev = first;
    }
}

void LinkedList::add_node(Node * node)
{
    LinkedList::debug_add_node(node);
    ++length;
}

void LinkedList::debug_add_node(Node* node) 
{
    debug_data.push_back(node);
}


void LinkedList::insert_front(int val)
{
    Node * node = new Node(val);

    add_node(node);

    if(!head)
    {
        head = tail = node;
    }        
    else
    {
        link(head , node);
        head = node;
    }
}

void LinkedList::insert_end(int val)
{
    Node * node = new Node(val);

    if(!head)
    {
        head = tail = node;
    }
    else
    {
        link(tail , node);
        tail = node;      
    }


}



void LinkedList::embed_after(Node * prv , int val)
{
    //Add a node with vlaue between node and It's next;
    Node * middle = new Node(val);
    ++length;
    //debug_add_node(middle);

    Node * node_after = prv->next;
    link(prv , middle);
    link(middle , node_after);    
}

void LinkedList::insert_sorted(int val)
{
    if(!length || val <= head->data)
    {
        LinkedList::insert_front(val);
    }
    else if(tail->data <= val)
    {
        LinkedList::insert_end(val);
    }
    else
    {
        //Find the I am less than. Then Insert before it.
        for(Node * curr = head ; curr ; curr = curr->next)
        {
            if(val <= curr->data)
            {
                embed_after(curr->prev , val);
                break;
            }
        }
    }

}

void LinkedList::delete_front(void)
{
    if(!head)
    {
        return;
    }
    Node * current = head->next;
    LinkedList::delete_node(head);
    head  = current;

    //Integrity Change
    if(head)
        head->prev = nullptr;
    else if(!length)
        tail = nullptr;


}

void LinkedList::delete_end(void)
{
    if(!tail)
    {
        return;
    }
    Node * current = tail->prev;
    LinkedList::delete_node(tail);
    tail = current;

    //Integrity Change
    if(tail)
        head->next = nullptr;
    else if(!length)
        head = nullptr;

}

Node * LinkedList::delete_and_link(Node * node)
{

    Node * ret = node->prev; 
    link(node->prev , node->next);
    LinkedList::delete_node(node);
    return ret;
    
}

void LinkedList::delete_node_with_key(int val)
{
    if(!length)
    {
        return;
    }
    else if(head->data == val)
    {
        LinkedList::delete_front();
    }
    else
    {
        for(Node * curr = head ; curr ; curr = curr->next)
        {
            if(curr->data == val)
            {
                curr = LinkedList::delete_and_link(curr);
                if(!curr->next)
                {
                    tail = curr;
                }
                break;
            }
        }
    }

}


void LinkedList::delete_node(Node* node) 
{
    debug_remove_node(node);
    --length;
    delete node;
}

void LinkedList::debug_remove_node(Node* node)
{
    auto it = std::find(debug_data.begin(), debug_data.end(), node);
    if (it == debug_data.end())
        std::cout << "Node does not exist\n";
    else
        debug_data.erase(it);
}