#include <bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* construct(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int>& mp){
    
    if(inStart>inEnd || postStart>postEnd) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(postorder[postEnd]);
    int inRoot = mp[root->data];
    int numleft = inRoot - inStart;
    
    root->left = construct(inorder, inStart, inRoot-1, postorder, postStart, postStart + numleft -1 , mp);
    
    root->right = construct(inorder, inRoot+1,inEnd, postorder, postStart+numleft, postEnd-1, mp);
    
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
    if(inorder.size()!=postorder.size()) return NULL;
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    
    return construct(inorder,0, inorder.size()-1, postorder,0,postorder.size()-1, mp);
    
    
}
