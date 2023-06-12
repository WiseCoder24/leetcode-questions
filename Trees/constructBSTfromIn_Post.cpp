/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Medium
6.6K
97
Companies
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
    
    int search(vector<int> &inorder,int start,int end,int val){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int> &inorder,vector<int>& postorder,int start, int end,int &idx){
        
        if(start>end) return NULL;
        int val = postorder[idx];
        idx--;
        TreeNode* curr = new TreeNode(val);
        if(start==end) return curr;
        int pos = search(inorder,start,end,val);
        curr->right = build(inorder,postorder,pos+1,end,idx);
        curr->left = build(inorder,postorder,start,pos-1,idx);
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start = 0;
        int end = inorder.size()-1;
        int idx =postorder.size()-1;
        TreeNode* ans = build(inorder,postorder,start,end,idx);
        return ans;
    }
};