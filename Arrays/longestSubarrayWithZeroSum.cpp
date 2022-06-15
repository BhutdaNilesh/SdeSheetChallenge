#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    map<int,int>mp;
    mp[0]=0;
    int currSum=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        currSum+=arr[i];
        if(mp.find(currSum)!=mp.end()){
            ans = max(ans, i+1-mp[currSum]);
        }
        else mp[currSum] = i+1;
    }
    
    return ans;

}