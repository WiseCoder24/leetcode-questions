/*
226. Invert Binary Tree
Easy

Given the root of a binary tree, invert the tree, and return its root.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root!=NULL){
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left,root->right);
        }
        return root;
    }
};