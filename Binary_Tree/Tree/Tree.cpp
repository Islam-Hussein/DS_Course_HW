
#include "Tree.h"

using namespace std;

void BinaryTree::_print_inorder(void)
{
    TreeNode * current = root;

    if(!current)
        return;

    _print_inorder(current->left);
    cout << current->data << " ";
    _print_inorder(current->right);
}

int BinaryTree::count(TreeNode * root)
{
    if(!root)
        return 0;
    
    return count(root->right) + count(root->left) + 1;
}

bool BinaryTree::is_BTPerfect(void)
{
    TreeNode * current = root;

    return is_Perfect(current);
}

bool BinaryTree::is_Perfect(TreeNode * root)
{
    if(!root)   
        return true;

    if(is_leaf(root))
        return true;
    
    if(count(root->left) != count(root->right))
        return false;

    return is_Perfect(root->left) && is_Perfect(root->right);
}



int BinaryTree::maxDepth(TreeNode * root)
{
    if(!root)
        return 0;
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return max(l , r) + 1;
}

int BinaryTree::maximumValue(TreeNode * current)
{

    if(!current)
        return INT_MIN;

    int maximum = current->data;
    int l = maximumValue(current->left);
    int r = maximumValue(current->right);

    maximum = max(maximum , l);
    maximum = max(maximum , r);

    return maximum;
}

bool BinaryTree::is_fullBT(void)
{
    return is_fullBT(root);
}


bool BinaryTree::is_fullBT(TreeNode * root)
{
    if(!root)
        return false;

    if(is_leaf(root))
        return true;
    if((root->left && !root->right) || (!root->left && root->right))
        return false;

    if((root->left && root->right))
        return is_fullBT(root->left) && is_fullBT(root->right);
}

bool BinaryTree::is_leaf(TreeNode * root)
{
    if(!root)
        return false;

    if((!root->right) && (!root->left))
        return true;
    else
        return false;
}

int BinaryTree::TreeSum(TreeNode * root)
{
    if(!root)
        return 0;
    
    return root->data + TreeSum(root->left)+ TreeSum(root->right);  
}

int BinaryTree::TreeSum(void)
{
    return TreeSum(root);
}

 
int BinaryTree::_maximumValue(void)
{
    TreeNode * current = root;

    int maximumVal = maximumValue(current);

    return maximumVal;
}

void BinaryTree::_print_inorder(TreeNode * current)
{
    if(!current)
        return;

    _print_inorder(current->left);
    cout << current->data << " ";
    _print_inorder(current->right);

    /*
    if(left)
    {
        left->print_inorder();
    }

    cout << data << " ";

    if(right)
    {
        right->print_inorder();
    }
    */
   
}
/*
int BinaryTree::maxTree()
{
    if(!left || !right)
        return;

    
    int left_max = max(root->left);
    int right_max = max(root->right);
    int me = root->data;
    int lr = max(left_max , right_max);
    
    return max(lr , me); 
}
*/

void BinaryTree::add(vector<int> values , vector<char> directions)
{
    assert(values.size() == directions.size());
    TreeNode * current = this->root;

    for(int i = 0 ;  i < (int) values.size() ; ++i )
    {
        if (directions[i] == 'L')
        {
            if(!current->left)
                current->left = new TreeNode(values[i]);
            else
                assert(current->left->data == values[i]);
            current = current->left;
        }
        else
        {
            if(!current->right)
                current->right = new TreeNode(values[i]);
            else
                assert(current->right->data == values[i]);
            current = current->right;
        }
    }
}



