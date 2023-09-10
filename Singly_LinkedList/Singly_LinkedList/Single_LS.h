#ifndef SINGLE_LS_H_
#define SINGLE_LS_H_

#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
    int data {};
    Node * next {};
    Node(int data) : data (data) {}

    ~Node()
    {
        std::cout << "Destroy Value : " << data << " at address : " << this << "\n";
    }
};

class LinkedList
{
private:
    Node * head{};
    Node * tail{};
    int length = 0;

    std::vector<Node*> debug_data;

public:
    void Print_LS();

    void debug_add_node(Node * node);

    void add_node(Node * node);

    void debug_remove_node(Node * node);

    void delete_node(Node* node);

    void Insert_end(int val);

    void Insert_front(int val);

    void Delete_front(void);

    void delete_next_node(Node * node);

    void delete_with_key(int val);


    int search(int val);

    Node* get_nth(int n);



};

#endif