/*
99. Recover Binary Search Tree
Medium

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
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
    int maxi = INT_MIN;
        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;
    void inorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        maxi = max(maxi, root->val);
        if(maxi==root->val){
            if(node2==nullptr){
                node1 = root;
            }
        }
        else{
            node2 = root;
        }
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(node1->val,node2->val);
        
    }
};