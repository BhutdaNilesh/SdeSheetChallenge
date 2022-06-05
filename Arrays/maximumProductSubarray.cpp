int maximumProduct(vector<int> &nums, int n)
{
    // Write your code here
    int right=nums[0], left = nums[0];
    bool isZero=false;
    int prod=1;
    for(int i=0;i<n;i++){
        prod*=nums[i];
        if(nums[i]==0){
            prod=1;
            isZero = true;
            continue;
        }
        left = max(left, prod);
    }
    prod=1;
    for(int i=n-1;i>=0;i--){
        prod*=nums[i];
        if(nums[i]==0){
            isZero = true;
            prod=1;
            continue;
        }
        right = max(right, prod);
    }
    
    if(isZero) return max(max(left, right),0);
    return max(left, right);
}


// // M2: Kadane's Algorithm
// int maximumProduct(vector<int> &nums, int n)
// {
// 	// Write your code here
//     int prod1 = nums[0], prod2 = nums[0], ans=nums[0];
    
//     for(int i=1;i<n;i++){
//         int curr = max(nums[i], max(prod1*nums[i],prod2*nums[i]));
//         prod2 = min(nums[i], min(prod1*nums[i], prod2*nums[i]));
//         prod1 = curr;
//         ans = max(ans, prod1);
//     }
//     return ans;
    
// }
