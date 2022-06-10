#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string s;
    if(!root) return "";
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        if(it==NULL) s.append("#,");
        else s.append(to_string(it->data)+',');
        
        if(it){
            q.push(it->left);
            q.push(it->right);
        }
    }
//     cout<<s<<endl;
    return s;
}

TreeNode<int>* deserializeTree(string &data)
{
 //    Write your code here for deserializing the tree
    
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        
        getline(s,str,',');
        if(str=="#"){
            node->left = NULL;
        }else{
            TreeNode<int>* leftNode = new TreeNode<int>(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        
        getline(s,str,',');
        if(str=="#"){
            node->right = NULL;
        }else{
            TreeNode<int>* rightNode = new TreeNode<int>(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }   
    }
    return root;
}



