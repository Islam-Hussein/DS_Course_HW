#include "Tree/Tree.h"
using namespace std;



/*
void print_postfix(Node * current)
{
    cout << current->left->data<< " ";
    cout << current->right->data<< " ";
    cout << current->data<< " ";
}

void print_prefix(Node * current)
{
    cout << current->data<< " ";
    cout << current->left->data<< " ";
    cout << current->right->data<< " ";
}

void print_inorder(Node * current)
{
    if(!current)
        return;
    
    print_inorder(current->left);
    cout << current->data << " ";
    print_inorder(current->right);
}

void print_postorder(Node * current)
{
    if(!current)
        return;

    print_postorder(current->left);
    print_postorder(current->right);
    cout << current->data << " ";
}

void print_preorder(Node * current)
{
    if(!current)
        return;
    cout << current->data << " ";
    print_preorder(current->left);
    print_preorder(current->right);
}

int max(Node* root)
{
    int left = max(root->left);
    int right = max(root->right);
    int me = root->data;
    int lr = max(left , right);
    
    return max(lr , me); 
}
*/

int main()
{
    /*
    Node* plus = new Node('+');
    Node* node1 = new Node('1');
    Node* node2 = new Node('2');

    Node* multiply = new Node('*');

    Node* node3 = new Node('3');
    Node* node4 = new Node('4');
    Node* node5 = new Node('5');

    plus->left = node1;
    plus->right = node2;
    
    multiply->left = plus;
    multiply->right = node4;
    */

	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

    tree._print_inorder();    

    cout << "\n";
    cout << tree._maximumValue() << "\n";

    cout << "\n Tree Sum = "<< tree.TreeSum()<< endl;

    
    //cout << root->right->left->data << "\n" ;
    //cout << root->data << "\n" ;
    
    //print_inorder(plus);
    //print_postorder(multiply);
    //cout << "Hello World\n";
}