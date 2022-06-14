/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int successor(BinaryTreeNode<int>* root, int key){
    BinaryTreeNode<int>* succ = NULL;
    
    while(root!=NULL){
        if(root->data <= key){
            root = root->right;
        }else{
            succ = root;
            root = root->left;
        }
    }
    if(succ==NULL) return -1;
    return succ->data;
}

int predecessor(BinaryTreeNode<int>* root, int key){
    BinaryTreeNode<int>* pre = NULL;
    while(root!=NULL){
        if(root->data >= key){
           
            root = root->left;
        }else{
             pre = root;
            root = root->right;
        }
    }
    if(pre==NULL) return -1;
    return pre->data;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pre = predecessor(root,key);
    int succ = successor(root,key);
    return {pre,succ};
}
