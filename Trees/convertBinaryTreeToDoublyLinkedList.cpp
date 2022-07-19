/*************************************************************
 
    Following is the Binary Tree node structure

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
void inorder(BinaryTreeNode<int>* root, vector<int>& res){
    if(!root) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right,res);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<int>res;
    inorder(root,res);
    
    BinaryTreeNode<int>* head = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* curr = head;
    
    for(int i=0;i<res.size();i++){
        BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(res[i]);
        curr->right = temp;
        temp->left = curr;
        curr = temp;
    }
    return head->right;
}