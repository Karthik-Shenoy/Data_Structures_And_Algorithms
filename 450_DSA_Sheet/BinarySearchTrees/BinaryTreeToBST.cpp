#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// The given root is the root of the Binary Tree
// Return the root of the generated BST
Node *bst_root = NULL;
void dfs(Node *root)
{
    if (!root)
        return;
    dfs(root->left);
    dfs(root->right);
    insert(root->data);
}
Node *insert(int val)
{
    if (!bst_root)
        bst_root = new Node(val);
    Node *prev = bst_root, *curr = bst_root;
    while (curr)
    {
        if (val > curr->data)
        {
            prev = curr;
            curr = curr->right;
        }
        else if (val < curr->data)
        {
            prev = curr;
            curr = curr->left;
        }
        else
            return NULL;
    }
    if (val < prev->data)
    {
        prev->left = new Node(val);
    }
    else
    {
        prev->right = new Node(val);
    }
}
Node *binaryTreeToBST(Node *root)
{
    // Your code goes here
    dfs(root);
    return bst_root;
}