/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* construct(vector<int>& arr, int i,int n){
    if(i>n) return NULL;
    int mid = i+ (n-i)/2;
    TreeNode<int>* root =new TreeNode<int>(arr[mid]);
    root->left = construct(arr, i,mid-1);
    root->right = construct(arr,mid+1,n);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if(n==0) return NULL;
    return construct(arr,0,n-1);
 
}