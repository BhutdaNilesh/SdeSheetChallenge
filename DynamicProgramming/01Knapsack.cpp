#include<bits/stdc++.h>

int solve(int ind, int W, vector<int>& val, vector<int>& wt,vector<vector<int>>& dp){
    if(ind==0){
        if(wt[0]<=W) return val[0];
        else return 0;
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int notTake = 0 + solve(ind-1, W, val, wt,dp);
    int take = INT_MIN;
    if(wt[ind]<=W){
        take = val[ind] + solve(ind-1, W-wt[ind], val, wt,dp);
    }
    return dp[ind][W] = max(take, notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int W)
{
	// Write your code here
    vector<vector<int>>dp(n, vector<int>(W+1,-1));
    return solve(n-1,W, values, weights,dp);
}


//Tabulation

int maxProfit(vector<int> &val, vector<int> &wt, int n, int maxW)
{
	// Write your code here
    vector<vector<int>>dp(n, vector<int>(maxW+1,0));
    
    for(int W =wt[0];W<maxW;W++){
        dp[0][W] = val[0];
    }
    
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxW;W++){
            int notTake = 0 + solve(ind-1, W, val, wt,dp);
            int take = INT_MIN;
            if(wt[ind]<=W){
                take = val[ind] + solve(ind-1, W-wt[ind], val, wt,dp);
            }
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n-1][maxW];
}