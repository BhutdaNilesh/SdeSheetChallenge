#include<bits/stdc++.h>
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long maxi;
long long maxSumPath(TreeNode<int>* root){
    if(root==NULL) return 0;

    long long left = maxSumPath(root->left);
    long long right = maxSumPath(root->right);

    maxi = max(maxi, left+right+ root->val);

    return root->val + max(left,right);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return -1;
    if(!root->left || !root->right) return -1;
    maxi=0;
    maxSumPath(root);
    return maxi;
}