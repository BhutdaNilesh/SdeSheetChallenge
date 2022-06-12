
#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int>*root){
    return !root->left && !root->right;
}
void addLeft(TreeNode<int>* root, vector<int>&res){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isleaf(curr)) res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr = curr->right;
    }
}

void addRight(TreeNode<int>* root, vector<int>&res){
    TreeNode<int>* curr = root->right;
    vector<int>temp;
    while(curr){
        if(!isleaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    reverse(temp.begin(),temp.end());
    for(auto it: temp){
        res.push_back(it);
    }
}

void addLeaves(TreeNode<int>* root, vector<int>&res){
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
//     if(!root) return ans;
    if(!isleaf(root)) ans.push_back(root->data);
    addLeft(root, ans);
    addLeaves(root,ans);
    addRight(root, ans);
    return ans;
}