// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        int split = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        
        vector<int> linorder(inorder.begin(), inorder.begin()+split);
        vector<int> lpreorder(preorder.begin()+1, preorder.begin()+1+linorder.size());
        root->left = buildTree(lpreorder, linorder);
        
        vector<int> rpreorder(preorder.begin()+1+linorder.size(), preorder.end());
        vector<int> rinorder(inorder.begin()+split+1, inorder.end());
        root->right = buildTree(rpreorder, rinorder);
        
        return root;
    }
};