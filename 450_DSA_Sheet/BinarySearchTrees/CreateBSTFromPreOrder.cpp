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

TreeNode *construct(vector<int> &inorder, vector<int> &preorder, int &index, int L, int R)
{
    if (index == preorder.size())
        return NULL;

    TreeNode *root = NULL;
    int i = -1, flag = 0;

    for (i = L; i <= R; i++)
    {
        if (preorder[index] == inorder[i])
        {
            flag = 1;
            root = new TreeNode(inorder[i]);
            break;
        }
    }

    if (!flag)
        return NULL;
    if (i - 1 >= 0 && (i - 1) >= L)
    {
        index++;
        root->left = construct(inorder, preorder, index, L, i - 1);
    }
    if (i + 1 < inorder.size() && (i + 1) <= R)
    {
        index++;
        root->right = construct(inorder, preorder, index, i + 1, R);
    }
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    int index = 0;
    return construct(inorder, preorder, index, 0, inorder.size() - 1);
}
