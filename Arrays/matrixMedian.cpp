#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    vector<int>ans;
    for(auto it: matrix){
        for(auto i:it){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    int n = ans.size();
    if(n%2){
        return ans[n/2];
    }else{
        return ans[n/2 -1];
    }
    
}