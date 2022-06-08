#include <bits/stdc++.h>

/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int, int>mp;
    queue<pair<BinaryTreeNode<int>* , int>>q;
    q.push({root,0});
    vector<int>ans;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int>* root = it.first;
        int line = it.second;
        mp[line] = root->data;
        if(root->left){
            q.push({root->left, line-1});
        }
        if(root->right){
            q.push({root->right, line+1});
        }
    }
    
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
    
}
