/*
501. Find Mode in Binary Search Tree
Easy

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
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
    vector<int> inorder;
    void inSeq(TreeNode* root){
        if(root==NULL)
            return;
        inSeq(root->left);
        inorder.push_back(root->val);
        inSeq(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inSeq(root);
        int maxFreq = INT_MIN;
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]++;
        }
        for(auto i:m){
            maxFreq = max(maxFreq,i.second);
        }
        for(auto i:m){
            if(i.second==maxFreq)
                ans.push_back(i.first);
        }
        return ans;
    }
};