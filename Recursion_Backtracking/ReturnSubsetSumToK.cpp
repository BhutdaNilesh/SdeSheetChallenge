
void solve(int ind, vector<vector<int>>&ans, vector<int>& res, vector<int>& arr, int target){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(res);
        }
        return;
    }
    
    // pick

    res.push_back(arr[ind]);
    solve(ind+1, ans, res, arr, target-arr[ind]);
    res.pop_back();

    //Not pick
    solve(ind+1, ans, res, arr, target);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
//     sort(arr.begin(),arr.end());
    vector<int>res;
    solve(0, ans, res, arr, k);
    return ans;
    
}