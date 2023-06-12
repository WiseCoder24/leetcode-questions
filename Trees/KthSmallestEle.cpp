/*
230. Kth Smallest Element in a BST
Medium

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
 vector<int> inorderArray;
    void inorder(TreeNode* root){
            if(root == NULL){
            return;
        }
        inorder(root->left);
        inorderArray.push_back(root->val);
        inorder(root->right);
        }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return inorderArray[k-1];
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        // Base case 
        if(root==NULL) return -1;
        int leftAns = kthSmallest(root->left,k);
        if(leftAns != -1) return leftAns;
        k--;
        if(k==0) return root->val;
        int rightAns = kthSmallest(root->right,k);
        return rightAns;
    }
};