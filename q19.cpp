/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/
#include "headers.h"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxpathsum;
int gainfromtree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftchildsum = max(gainfromtree(root->left), 0);
    int rightchildsum = max(gainfromtree(root->right), 0);

    int gainfromtree = max(leftchildsum,rightchildsum) + root->val;
    maxpathsum = max(maxpathsum,leftchildsum+rightchildsum+root->val);

    return gainfromtree;
}
int maxPathSum(TreeNode *root)
{
    maxpathsum = INT32_MIN;
    gainfromtree(root);
    return maxpathsum;
}