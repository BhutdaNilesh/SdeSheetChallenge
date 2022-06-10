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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>ans;
    if(!root) return ans;
    queue<BinaryTreeNode<int>* >q;
    q.push(root);
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int>res(size);
        
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            int ind = leftToRight ? i : size - i -1;
            res[ind] = node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto it: res){
            ans.push_back(it);
        }
    }
    return ans;
        
}
