// Leetcode

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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            int first,last;
            int min = q.front().second;
            for(int i=0;i<n;i++){
                auto it = q.front(); 
                q.pop();
                long long curr_id =it.second-min;
                TreeNode* node = it.first;
                if(i==0) first= curr_id;
                if(i==n-1) last = curr_id;
                if(node->left){
                    
                    q.push({node->left, curr_id*2 +1});
                }
                if(node->right){
                    
                    q.push({node->right, curr_id*2 +2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
        
        
    }
};


// codestudio

/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int ans=0;
    if(!root) return 0;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        ans = max(ans, n);
        for(int i=0;i<n;i++){
            auto it = q.front();
            q.pop();
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
        }
    }
    return ans;
}



