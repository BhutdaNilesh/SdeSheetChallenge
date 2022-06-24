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

class BSTiterator
{
    public:
    vector<int>ans;
    int pos;
    void inorder(TreeNode<int>* root){
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->data);
        inorder(root->right);
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pos=0;
        inorder(root);
    }

    int next()
    {
        // write your code here
        return ans[pos++];
    }

    bool hasNext()
    {
        // write your code here
        return ans.size()!=pos;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/