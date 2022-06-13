int solve(int ind, vector<int>& prices, int n, vector<vector<int>>& dp){
    
    if(ind==0) return n*prices[0];
    if(dp[ind][n]!=-1) return dp[ind][n];
    int notTake = solve(ind-1,prices,n,dp);
    
    int take = -1e9;
    if(ind+1<=n) take = prices[ind] + solve(ind,prices,n-ind-1,dp);
    
    return dp[ind][n] = max(take, notTake);
    
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
    return solve(n-1, price,n, dp);
}
