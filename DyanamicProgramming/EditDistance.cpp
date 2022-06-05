int solve(int i, int j, string &str1, string & str2, vector<vector<int>>& dp){
    if(i==0) return j;
    if(j==0) return i;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(str1[i-1]==str2[j-1]){
        return dp[i][j] = solve(i-1, j-1, str1, str2, dp);
    }else{
        return dp[i][j] = 1 + min(solve(i-1,j, str1, str2,dp), min(solve(i,j-1,str1,str2, dp), solve(i-1,j-1, str1, str2, dp)));
    }
    
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    return solve(n,m, str1,str2,dp);
    
}