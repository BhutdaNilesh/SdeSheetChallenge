#include<bits/stdc++.h>

void solve(int ind, vector<vector<int>>& ans, vector<int>& res, vector<int>& arr, int target){
    
    if(target==0){
        ans.push_back(res);
        return;
    }
    
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        res.push_back(arr[i]);
        solve(i+1, ans, res, arr, target-arr[i]);
        res.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>res;
    solve(0, ans, res,arr, target);
    return ans;
}
