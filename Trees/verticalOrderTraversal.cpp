#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int, map<int, vector<int>>>nodes;
    queue<pair<TreeNode<int>* , pair<int, int>>>q;
    q.push({root, {0,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int>* root = it.first;
        int x = it.second.first;
        int y = it.second.second;
        nodes[x][y].push_back(root->data);
        if(root->left){
            q.push({root->left, {x-1,y+1}});
        }
        if(root->right){
            q.push({root->right, {x+1, y+1}});
        }
    }
    
    vector<int>ans;
    for(auto it: nodes){
//         vector<int>res;
        for(auto i:it.second){
            ans.insert(ans.end(), i.second.begin(), i.second.end());
        }
    }
    return ans;
}



//Leetcode

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>nodes;
        queue<pair<TreeNode* , pair<int, int>>>q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* root = it.first;
            int x = it.second.first;
            int y = it.second.second;
            nodes[x][y].insert(root->val);
            if(root->left){
                q.push({root->left, {x-1,y+1}});
            }
            if(root->right){
                q.push({root->right, {x+1, y+1}});
            }
        }

        vector<vector<int>>ans;
        for(auto it: nodes){
            vector<int>res;
            for(auto i:it.second){
                res.insert(res.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};