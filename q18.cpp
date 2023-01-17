/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum) 
{
    if(root == nullptr)
        return false;
   
    if(root->left!=nullptr && root->right!=nullptr)
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    else if(root->right !=nullptr)
        return hasPathSum(root->right,targetSum-root->val);
    else if(root->left!=nullptr)
        return hasPathSum(root->left,targetSum-root->val);
    else // it is the leafnode
        return (targetSum==root->val);
}