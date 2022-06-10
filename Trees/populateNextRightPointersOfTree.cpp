#include <bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    
    if(!root) return;
    
    queue<BinaryTreeNode<int>* >q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto it = q.front();
            q.pop();
            
            if(i==size-1) it->next= NULL;
            else it->next = q.front();
            
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
        }
    }
    
}