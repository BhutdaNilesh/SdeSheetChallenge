void solve(int ind, vector<int>&ans, vector<int>& nums, int sum){
    if(ind==nums.size()){
        ans.push_back(sum);
        return;
    }
    
    solve(ind+1, ans, nums, sum);
    solve(ind+1, ans, nums, sum+nums[ind]);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    solve(0, ans, num, 0);
    sort(ans.begin(),ans.end());
    return ans;
}