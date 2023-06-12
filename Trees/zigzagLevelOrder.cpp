// 103. Binary Tree Zigzag Level Order Traversal
// Medium

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return vector<vector<int>> ();
        }
        vector<vector<int>> answer;
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool leftToRight = true;
        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                TreeNode* temp = nodeQueue.front();
                nodeQueue.pop();
                int index = leftToRight?i:(size-1-i);
                level[index] = temp->val;
                if(temp->left)
                    nodeQueue.push(temp->left);
                if(temp->right)
                    nodeQueue.push(temp->right);
                
            }
            leftToRight = !leftToRight;
            answer.push_back(level);
            
        }
        return answer;
    }
};