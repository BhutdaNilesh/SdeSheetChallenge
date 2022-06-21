#include<bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
    vector<int>dp(n);
    for(int i=0;i<n;i++){
        dp[i] = rack[i];
    }
    int maxi = rack[0];
    for(int i=1;i<n;i++){
        for(int prev = 0;prev<i;prev++){
            if(rack[i]>rack[prev]){
                dp[i] = max(dp[i], dp[prev]+ rack[i]);
                
            }
        }
        maxi = max(maxi, dp[i]);
    }
  
    return maxi;
}