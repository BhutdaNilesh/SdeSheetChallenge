#include <bits/stdc++.h> 

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    
    unordered_map<int,pair<int,int>>mp;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum = arr[i]+arr[j];
            mp[sum] = {i,j};
        }
    }
    
    for(int k=0;k<n-1;k++){
        for(int l=k+1;l<n;l++){
            
            int remaining = target - arr[k] - arr[l];
            
            if(mp.find(remaining)!=mp.end()){
                int i = mp[remaining].first;
                int j = mp[remaining].second;
                
                if(i!=k && i!=l && j!=k && j!=l){
                    return "Yes";
                }
            }
            
        }
    }
    return "No";
}
