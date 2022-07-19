/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class Node{
  public:
    int maxSize,  maxi,  mini;
    Node(int maxSize, int mini, int maxi){
        this->maxSize = maxSize;
        this->maxi = maxi; 
        this->mini = mini;  
    }
};

Node solve(TreeNode<int>* root){
    if(!root){
        return Node(0,INT_MAX,INT_MIN);
    }
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        if(left.maxi < root->data && root->data < right.mini){
            return Node(left.maxSize+right.maxSize+1, min(root->data, left.mini), max(root->data, right.maxi));
        }else{
            return Node(max(left.maxSize, right.maxSize), INT_MIN, INT_MAX);
        }
    
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return solve(root).maxSize;
}
