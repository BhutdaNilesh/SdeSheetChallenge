/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool help(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right){
    if(!left || !right){
        return left==right;
    }
    if(left->data!=right->data) return false;
    
    return help(left->left, right->right) && help(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
 
    if(!root) return true;
    return help(root->left, root->right);
    
}