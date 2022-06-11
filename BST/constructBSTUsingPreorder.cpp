// Naive 

#include<bits/stdc++.h>

/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* construct(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>&mp){
    
    if(inStart> inEnd || preStart>preEnd) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);
    int inRoot = mp[root->data];
    int numleft = inRoot - inStart;
    
    root->left = construct(preorder, preStart+1, preStart+numleft, inorder, inStart, inRoot-1, mp);
    
    root->right = construct(preorder, preStart+numleft+1, preEnd, inorder, inRoot+1, inEnd, mp);
}

TreeNode<int>* preOrderTree(vector<int> &preorder){
    // Write your code here.
    vector<int>inorder = preorder;
    sort(inorder.begin(),inorder.end());
    
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    
    return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
}


// Better using property of BST
