#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here 
    unordered_map<int, int>mp;
    for(auto it: arr){
        mp[it]++;
    }
    pair<int,int>ans;
    for(auto it:mp){
        if(it.second>1){
            ans.second = it.first;
        }
    }
    for(int i=1;i<=n;i++){
        if(mp.find(i)==mp.end()){
            ans.first = i;
            break;
        }
    }
    return ans;
}
