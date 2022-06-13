// Momoisation code

#include <bits/stdc++.h>

long solve(int ind, int *denominations, int n, int value, vector<vector<long>>& dp){
    
    if(ind==0){
        return (value%denominations[0]==0);
    }
    if(dp[ind][value]!=-1) return dp[ind][value];
    long notTake = solve(ind-1, denominations, n, value,dp);
    long take=0;
    if(denominations[ind]<=value) take = solve(ind, denominations, n, value - denominations[ind],dp);
    
    return dp[ind][value] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>>dp(n, vector<long>(value+1,-1));
    return solve(n-1, denominations, n, value,dp);
}



// Tabulation code

#include <bits/stdc++.h>


long countWaysToMakeChange(int *denominations, int n, int Value)
{
    //Write your code here
    vector<vector<long>>dp(n+1, vector<long>(Value+1,0));
    
    for(int value=0;value<=Value;value++){
        if((value%denominations[0])==0) dp[0][value] = 1;
    }
    
    for(int ind=1;ind<n;ind++){
        for(int value=0;value<=Value;value++){
            long notTake = dp[ind-1][value];
            long take=0;
            if(denominations[ind]<=value) take = dp[ind][value- denominations[ind]];

            dp[ind][value] = take + notTake;
        }
    }
    
    return dp[n-1][Value];
}