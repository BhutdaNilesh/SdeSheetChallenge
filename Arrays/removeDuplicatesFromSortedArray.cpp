#include<bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    
    map<int,int>mp;
    for(auto it:arr){
        mp[it]++;
    }
    
    return mp.size();
}