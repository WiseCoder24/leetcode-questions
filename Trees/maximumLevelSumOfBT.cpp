/*
1161. Maximum Level Sum of a Binary Tree
Medium
2.5K
80
Companies
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
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
    void levelOrder(TreeNode* root,int &ans){
        int level = 0;
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int sum = 0;
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* temp = q.front();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            if(sum>maxSum){
                maxSum = sum;
                ans = level;
            }
        }
    }
    int maxLevelSum(TreeNode* root) {
        int ans = -1;
        levelOrder(root,ans);
        return ans;
    }
};