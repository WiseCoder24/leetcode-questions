/*
129. Sum Root to Leaf Numbers
Medium

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
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
    void solve(TreeNode* root, int& sum, int num=0){
        
        if(root == NULL){            
                       
            return ;
        }
        
        int digit = root->val;
        num = num*10 + digit;        
        if(root->left==NULL && root->right==NULL)
            sum += num; 
            
        solve(root->left, sum, num);
        solve(root->right, sum, num);
        return ;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root,sum,0);
        return sum;
    }
};