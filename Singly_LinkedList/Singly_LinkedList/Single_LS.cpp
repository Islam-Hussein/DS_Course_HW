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
    LinkedList::add_node(item);

    if(!head)
    {
        head = tail = item;
    }
    else
    {
        tail->next = item;
        tail = item;
    }
}

void LinkedList::add_node(Node * node)
{
    debug_add_node(node);
    ++length;
}

void LinkedList::Insert_front(int val)
{
    Node * item = new Node(val);
    LinkedList::add_node(item);


    if(!head)
    {
        head = tail = item;
    }
    else
    {
        item->next = head;
        head = item;
    }
}

void LinkedList::Delete_front(void)
{
    if(!head)
        return;

    Node * Temp_Node = head->next;

    delete(head);

    head = Temp_Node; 
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


void LinkedList::delete_with_key(int val)
{
    bool is_deleted = false;

    if (!length)
    {
        std::cout << "Empty List !\n";
        return;
    }
    
    // Handle the case where the head node has the key to be deleted
    while (head && head->data == val)
    {
        LinkedList::Delete_front();
    }

    Node* curr = head;
    Node* prv = nullptr;
    
    while (curr)
    {
        if (curr->data == val)
        {
            is_deleted =true;
            LinkedList::delete_next_node(prv);
            curr = prv->next; // Move curr to the next node after deletion
        }
        else
        {
            prv = curr;
            curr = curr->next;
        }
    }
    if(!is_deleted)
        std::cout << "Value Not Found !\n";
}


/*
void LinkedList::delete_with_key(int val)
{
    if(!length)
        std::cout << "Empty List !\n";
    
    else if (head->data == val)
        LinkedList::Delete_front();
    else
        for(Node * curr = head , *prv = nullptr; curr ; prv = curr , curr = curr->next )
        {
            if(curr->data == val)
            {
                LinkedList::delete_next_node(prv);
            }
        }
        std::cout << "Value Not Found !\n";
}
*/

void LinkedList::delete_node(Node* node) {
    debug_remove_node(node);
    --length;
    delete node;
}

void LinkedList::delete_next_node(Node * node)
{
    Node * to_delete = node->next;
    bool is_tail = (to_delete == tail);

    node->next = node->next->next;
    LinkedList::delete_node(to_delete);

    if(is_tail)
        tail = node;

}

void LinkedList::delete_last_node(void)
{
    Node * key = LinkedList::get_nth(length-1);
    LinkedList::delete_next_node(key);
}


void LinkedList::delete_even_positions(void)
{
    if(length <= 1)
        std::cout << "Empty Linked List or Has one Element! \n";
        return;

    for(Node * curr = head->next , *prv = head ; curr ; )
    {
        delete_next_node(prv);

        if(!prv->next)
        {
            break;
        }
        curr=curr->next->next; 
        prv= prv->next;
    }
}

void LinkedList::debug_add_node(Node * node)
{
    debug_data.push_back(node);
}

void LinkedList::debug_remove_node(Node * node)
{
    auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			std::cout << "Node does not exist\n";
		else
			debug_data.erase(it);
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

void LinkedList::swap_pairs(void)
{
    if(!length)
    {
        std::cout << "Empty Linked List! \n";
        return;
    }
    for(Node * curr = head   ; curr ; curr = curr->next)
    {
    if(curr->next)
        {
            std::swap(curr->data , curr->next->data);
            curr = curr->next;
        }
    }
    
}

void LinkedList::reverse(void)
{
    if(length <= 1)
    {
        std::cout << "Empty Linked List or has Only one Element! \n";
        return;
    }

    tail = head;
    Node * prv = head;
    head = head->next;

    while(head)
    {
        //Store & reverse link
        Node * next = head->next;
        head->next = prv;

        //move step
        prv  = head;
        head = next;
    }

    //Finalize head and Tail
    head = prv;
    tail->next = nullptr;
}

