/*
114. Flatten Binary Tree to Linked List
Medium

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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
/*******************Morris Treversal*******************/
class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode* curr = root;
        while(curr!=NULL){
        
        if(curr->left){
            TreeNode* pred = curr->left;
            while(pred->right){
                pred = pred->right;
            }   
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
            curr = curr->right;
        }
        /*Root ke left ko null krna (Jugaad)
        curr = root;
        while(curr!=NULL){
            curr->left = NULL;
            curr = curr->right;
        }
        */
    }
};