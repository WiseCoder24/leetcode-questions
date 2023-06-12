/*
113. Path Sum II
Medium

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
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
/********Without backtracking*********/
class Solution {
public:
    void solve(TreeNode* root, int targetSum, int sum, vector<int> temp,vector<vector<int>> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
            sum+=root->val;
            if(sum==targetSum){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);
        sum+=root->val;
        solve(root->left,targetSum,sum,temp,ans);
        solve(root->right,targetSum,sum,temp,ans);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum,sum,temp,ans);
        return ans;
    }
};

/***********With backtracking*********/
class Solution {
public:
    void solve(TreeNode* root, int targetSum, int &sum, vector<int> &temp,vector<vector<int>> &ans){
        //Base case
        if(root==NULL) return;
        //Leaf node
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
            sum+=root->val;
            if(sum==targetSum){
                ans.push_back(temp);
            }
            temp.pop_back();
            sum -= root->val;
            return;
        }
        // Path creation
        temp.push_back(root->val);
        sum+=root->val;
        //recursion
        solve(root->left,targetSum,sum,temp,ans);
        solve(root->right,targetSum,sum,temp,ans);
        
        //backtrack
        temp.pop_back();
        sum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum,sum,temp,ans);
        return ans;
    }
};