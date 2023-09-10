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
    if(!length)
        std::cout << "Empty List !\n";
    
    else if (head->data == val)
        LinkedList::Delete_front();
    else
        for(Node * curr = head , *prv = nullptr; curr ; prv = curr , curr = curr->next )
        {
            if(curr->data == val)
                LinkedList::delete_next_node(prv);
                break;
        }
        std::cout << "Value Not Found !\n";
}

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

