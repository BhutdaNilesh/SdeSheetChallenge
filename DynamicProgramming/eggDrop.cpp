#include<bits/stdc++.h>

int cutLogs(int k, int n)
{
    // Write your code here.
    
    // it is similar problem to egg drop
    
    vector<vector<int>>dp(k+1, vector<int>(n+1,0));
    
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i==1){
                dp[i][j]=j;
            }else if(j==1){
                dp[i][j] = 1;
            }else{
                int mini = 1e9;
                
                for(int mj=j-1,pj=0;mj>=0;mj--,pj++){
                    int v1 = dp[i][mj];
                    int v2 = dp[i-1][pj];
                    int val = max(v1,v2);
                    mini = min(mini, val);
                    
                }
                dp[i][j] = mini+1;
            }
            
        }
    }
    return dp[k][n];
}


// Optimised

#include<bits/stdc++.h>
int solve(int k, int n, vector<vector<int>>& dp){
    
    if(k==1) return n;
    else if(n==0 || n==1) return n;
    
    if(dp[k][n]!=-1) return dp[k][n];
    int mini = 1e9;
    int low = 1;
    int high = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        int left = solve(k-1, mid-1,dp);
        int right = solve(k, n-mid, dp);
        
        int val = max(left, right);
        if(left>right){
            high = mid-1;
        }else{
            low = mid+1;
        }
        mini = min(mini, val);
    }
    return dp[k][n] = mini+1;
}

int cutLogs(int k, int n)
{
    // Write your code here.
    
    // it is similar problem to egg drop
    
    vector<vector<int>>dp(k+1, vector<int>(n+1,-1));
    
    return solve(k,n,dp);
}
