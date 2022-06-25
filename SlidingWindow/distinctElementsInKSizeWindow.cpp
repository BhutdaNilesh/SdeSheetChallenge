#include<bits/stdc++.h>


vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    map<int,int>mp;
    vector<int>ans;
    int i=0, j=0;
    int n = arr.size();
    while(j<n){
        mp[arr[j]]++;
        if(j-i+1<k){
            j++;
        }else if(j-i+1 ==k){
            int ele = arr[i];
            int x = mp.size();
            ans.push_back(x);
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}
