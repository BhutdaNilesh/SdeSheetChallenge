#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    queue<pair<TreeNode<int>*, int>>q;
    map<int, int>mp;
    
    vector<int>ans;
    if(!root) return ans;
    
    q.push({root,0});
    while(!q.empty()){
        auto it= q.front();
        q.pop();
        TreeNode<int>* root = it.first;
        int line = it.second;
        
        if(mp.find(line)==mp.end()) mp[line] = root->val;
        
        if(root->left){
            q.push({root->left,line-1});
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