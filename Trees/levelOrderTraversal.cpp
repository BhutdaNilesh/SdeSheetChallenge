/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>ans;
    
    if(!root) return ans;
    queue<BinaryTreeNode<int>* >q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto it = q.front();
            q.pop();
            ans.push_back(it->val);
            
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
        }
    }
    return ans;
}