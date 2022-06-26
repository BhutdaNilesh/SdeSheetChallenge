#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    vector<int>res;
    vector<int>ans;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res.push_back(a[i]+b[j]);
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    for(int i=0;i<k;i++){
        ans.push_back(res[i]);
    }
    return ans;
}