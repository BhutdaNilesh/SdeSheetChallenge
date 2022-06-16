#include<bits/stdc++.h>

void solve(int ind, vector<int>& res, vector<int>&arr, set<vector<int>>&st){
    
    if(ind==arr.size()){
        st.insert(res);
        return;
    }
    
    res.push_back(arr[ind]);
    solve(ind+1, res, arr, st);
    res.pop_back();
    solve(ind+1, res, arr,st);
    
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>res;
    set<vector<int>>st;
    solve(0, res, arr, st);
    
    for(auto it: st){
        ans.push_back(it);
    }
    return ans;
}