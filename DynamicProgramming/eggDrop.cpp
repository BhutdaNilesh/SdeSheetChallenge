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
