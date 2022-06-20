#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int>ans;
    for(auto it: kArrays){
        for(i:it){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
