/*
783. Minimum Distance Between BST Nodes
Easy

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
*/

//Solution 1
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
    int ans = INT_MAX; int prev = -1;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev>=0) ans = min(ans, root->val-prev);
        prev = root->val;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        
        inorder(root);
        return ans;
    }
};


//Solution 2

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
    vector<int> arr;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int diff = INT_MAX;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            diff = min(diff,arr[i+1]-arr[i]);
        }
        return diff;
    }
};