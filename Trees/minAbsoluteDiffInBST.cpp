// 530. Minimum Absolute Difference in BST
// Easy
// 3.3K
// 165
// Companies
// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

//Approach 1
/*
We can store the elements of BST in an array in sorted order (inorder) then we can find the difference between adjacent elements and return the min difference
*/
//Approach 2
/*
We can avoid using extra space using inorder directly in recursion
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
    int ans = INT_MAX;
    int prev = -1;
    int getMinimumDifference(TreeNode* root) {
        if(root->left!=NULL){
            getMinimumDifference(root->left);
        }
        if(prev>=0)
            ans = min(ans,abs(root->val-prev));
        prev = root->val;
        if(root->right!=NULL){
            getMinimumDifference(root->right);
        }
        return ans;
    }
};