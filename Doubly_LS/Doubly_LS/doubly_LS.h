#ifndef DOUBLY_LS_H_
#define DOUBLY_LS_H_


#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>

struct Node
{
    int data    { };
    Node * next { };
    Node * prev { };
    
    void set(Node* next, Node* prev) 
    {
        this->next = next;
        this->prev = prev;
    }

    Node(int data) : data(data) { }

    ~Node()
    {
        std::cout << "Node with value " << data << " at address : " << this << " Destroyed!\n";
    }

};

class LinkedList
{
private:
    Node * head { };
    Node * tail { };
    int length  { };
    
    std::vector<Node*> debug_data;	// add/remove nodes you use

public:

    void embed_after(Node * prv , int val);

    void add_node(Node * node);

	void debug_add_node(Node* node);

    void debug_remove_node(Node* node);

    void delete_node(Node * node);

    void delete_front(void);

    void delete_end(void);

    Node * delete_and_link(Node * node);

    void delete_node_with_key(int val);

    void insert_front(int val);

    void insert_end(int val);

    void insert_sorted(int val);

    void print(void);

    void print_length(void);

    //Homework
    void delete_all_nodes_with_key(int value);

    void delete_even_nodes(void);

    void delete_odd_nodes(void);
    
    bool is_palindrome(void);


    //Medium Homework
    std::vector<int> find_middle(void);

    std::vector<int> find_middle_using_fast_pointer(void);


};

void link(Node * first , Node * second);



#endif