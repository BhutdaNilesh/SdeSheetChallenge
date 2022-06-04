#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    unordered_map<int, int>mp;
    for(auto it: arr){
        mp[it]++;
    }
    
    int res = -1;
    for(auto it: mp){
        if(it.second>1){
            res=it.first;
        }
    }
    return res;
}
