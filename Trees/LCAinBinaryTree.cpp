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
TreeNode<int>* LCA(TreeNode<int> *root, int x, int y){
    if(!root || root->data==x ||root->data==y){
        return root;
    }
    
    TreeNode<int>* left = LCA(root->left,x,y);
    TreeNode<int>* right =LCA(root->right,x,y);
    
    if(left==NULL){
        return right;
    }else if(right==NULL){
        return left;
    }else{
        return root;
    }
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    TreeNode<int>* ans = LCA(root,x,y);
    return ans->data;
    
    
}