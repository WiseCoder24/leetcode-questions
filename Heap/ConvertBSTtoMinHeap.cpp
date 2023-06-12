// Convert BST to Min Heap
#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void createInorder(BinaryTreeNode* root, vector<int> &inorder){
	if(root==NULL) return;
	createInorder(root->left,inorder);
	inorder.push_back(root->data);
	createInorder(root->right,inorder);
}

void preOrder(BinaryTreeNode* root, vector<int>&inorder, int &index){
	if(root==NULL) return;
	root->data = inorder[index++];
	preOrder(root->left,inorder,index);
	preOrder(root->right,inorder,index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int> inorder;
	int index = 0;
	createInorder(root,inorder);
	preOrder(root,inorder,index);
	return root;
}