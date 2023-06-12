// Kth Ancestor in a Tree (GeeksForGeeks)
// Medium
// Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note: It is guaranteed that the node exists in the tree

//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

bool solve(Node *root, int &k, int node, int &ans){
    if(root==NULL) return 0;
    if(root->data==node) return true;
    
    bool left = solve(root->left,k,node,ans);
    bool right = solve(root->right,k,node,ans);
    if(left==true || right==true)
        k--;
    if(k==0){
        ans = root->data;
        // cout<<root->data<<" "<<endl;
        k=-1;
    } 
    return left||right;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    if(solve(root,k,node,ans)) return ans;
    return -1;
}