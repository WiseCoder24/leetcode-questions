/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
*/
/***********With optimisation**************/
class Solution {
public:
    int findPosition(map<int,int> &m,int target){    
        return m[target];
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int size,int &preIndex,int inorderStart, int inorderEnd,map<int,int> &m){
        //base case
        if(preIndex>=size || inorderStart>inorderEnd) return NULL;

        //Step 1
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(m,element);

        //Step 2: Solve root->left
        root->left = solve(inorder,preorder,size,preIndex,inorderStart,pos-1,m);
        // Step 3: solve root->right
        root->right = solve(inorder,preorder,size,preIndex,pos+1,inorderEnd,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = n-1;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        TreeNode* ans = solve(inorder,preorder,n,preIndex,inorderStart,inorderEnd,m);
        
        return ans;
    }
};

/***********Without optimisation**************/
class Solution {
public:
    int findPosition(vector<int>& inorder, int size, int target){
        for(int i=0;i<size;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int size,int &preIndex,int inorderStart, int inorderEnd){
        //base case
        if(preIndex>=size || inorderStart>inorderEnd) return NULL;

        //Step 1
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(inorder,size,element);

        //Step 2: Solve root->left
        root->left = solve(inorder,preorder,size,preIndex,inorderStart,pos-1);
        // Step 3: solve root->right
        root->right = solve(inorder,preorder,size,preIndex,pos+1,inorderEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = n-1;
        TreeNode* ans = solve(inorder,preorder,n,preIndex,inorderStart,inorderEnd);
        
        return ans;
    }
};