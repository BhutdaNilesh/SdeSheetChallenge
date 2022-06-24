/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void inorder(vector<int>& res,BinaryTreeNode<int> *root){
    if(!root) return;
    inorder(res, root->left);
    res.push_back(root->data);
    inorder(res, root->right);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int>res;
    inorder(res, root);
    
    int i=0, j = res.size()-1;
    while(i<j){
        if(res[i]+res[j]==k){
            return true;
        }else if(res[i]+res[j]>k){
            j--;
        }else{
            i++;
        }
    }
    return false;
    
}