#include <bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    
    vector<int>ans;
    priority_queue<pair<int,int>>pq;
    map<int,int>mp;
    for(auto it: arr){
        mp[it]++;
    }
    
    for(auto it:mp){
        pq.push({it.second, it.first});
    }
    
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}