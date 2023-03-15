#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<TreeNode *> searchBST(TreeNode *root, int val)
{
    TreeNode *curr = root;
    TreeNode *par = NULL;
    while (curr)
    {
        if (curr->val == val)
            return {par, curr};
        else if (curr->val > val)
        {
            par = curr;
            curr = curr->left;
        }
        else
        {
            par = curr;
            curr = curr->right;
        }
    }
    return {par, curr};
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    vector<TreeNode *> nodes = searchBST(root, key);
    TreeNode *curr = nodes[1], *par = nodes[0];
    // not found
    if (par && !curr)
        return root;
    // null tree
    if (!par && !curr)
        return NULL;
    // only root
    if (!par && curr->left == NULL && curr->right == NULL)
        return NULL;
    // delete root node
    if (!par)
    {
        if (curr->right == NULL)
            return curr->left;
        if (curr->left == NULL)
            return curr->right;
        TreeNode *leftSubtree = curr->left;
        root = curr->right;
    }
    TreeNode *leftSubtree = NULL;
    // Normal node to the left of parent node
    if (par->left == curr)
    {
        par->left = curr->right;
        if (curr->right == NULL)
        {
            par->left = curr->left;
        }
        leftSubtree = curr->left;
    }
    // Normal node to the right of parent node
    if (par->right == curr)
    {
        par->right = curr->right;
        if (curr->right == NULL)
        {
            par->right = curr->left;
        }
        leftSubtree = curr->left;
    }
    //deletion Logic
    curr = curr->right;
    if (!curr)
        return root;
    while (curr->left)
        curr = curr->left;
    curr->left = leftSubtree;
    return root;
}