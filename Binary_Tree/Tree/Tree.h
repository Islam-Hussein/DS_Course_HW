#ifndef TREE_H_
#define TREE_H_



#include <iostream>
#include <cassert>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode
{
    int data    { };
    TreeNode * left { };
    TreeNode * right{ };

    TreeNode(int data) : data(data) ,left(nullptr) , right(nullptr) {}
    TreeNode(int data , TreeNode *left , TreeNode * right)  : data(data) , left(left) , right(right){}
};

class BinaryTree
{
private:
    TreeNode * root {};

public:
    BinaryTree(int root_value) : root(new TreeNode(root_value)) {}

    void _print_inorder(TreeNode * current);

    void _print_inorder(void);

    void add(vector<int> values , vector<char> directions);

    int _maximumValue(void);

    int maximumValue(TreeNode * current);

    bool is_leaf(TreeNode * root);

    bool is_fullBT(TreeNode * root);

    bool is_fullBT(void);

    int count(TreeNode * root);

    bool is_Perfect(TreeNode * root);

    bool is_BTPerfect(void);

    int maxDepth(TreeNode * root);

    int TreeSum(TreeNode * root);

    int TreeSum(void);



    //int maxTree();

};


#endif