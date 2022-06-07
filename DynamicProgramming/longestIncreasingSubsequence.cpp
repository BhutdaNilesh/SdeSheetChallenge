class Solution {
public:
    int solve(int ind, int prevInd, vector<int>& arr, vector<vector<int>>& dp,int n){
        if(ind==n) return 0;
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];

        int len = 0 + solve(ind+1, prevInd,arr,dp,n);
        if(prevInd==-1 || arr[ind]>arr[prevInd]){
            len = max(len, 1+ solve(ind+1,ind,arr,dp,n));
        }
        return dp[ind][prevInd+1] = len;
    }



    int lengthOfLIS(vector<int>& arr) {

        // int n = arr.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int prevInd=ind-1;prevInd>=-1;prevInd--){
        //         int len = 0 + dp[ind+1][prevInd+1];
        //         if(prevInd==-1 || arr[ind]>arr[prevInd]){
        //             len = max(len, 1+ dp[ind+1][ind+1]);
        //         }
        //         dp[ind][prevInd+1] = len;
        //     }
        // }
        // return dp[0][0];

        int n = arr.size();
        vector<int>next(n+1,0), curr(n+1,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int prevInd=ind-1;prevInd>=-1;prevInd--){
                int len = 0 + next[prevInd+1];
                if(prevInd==-1 || arr[ind]>arr[prevInd]){
                    len = max(len, 1+ next[ind+1]);
                }
                curr[prevInd+1] = len;
            }
            next = curr;
        }
        return next[0];
        
    }
};