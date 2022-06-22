#include<bits/stdc++.h>

bool isPalindrome(string &s, int i, int j){
    while(i<=j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}

int solve(int i, string& s, int n, vector<int>& dp){
    if(i==n) return 0;
    
    if(dp[i]!=-1) return dp[i];
    int minPart = 1e9;
    for(int j=i;j<n;j++){
        if(isPalindrome(s,i,j)){
            int mini = 1+solve(j+1, s, n, dp);
            minPart = min(mini, minPart);
        }
    }
    return dp[i] = minPart;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int>dp(n,-1);
    return solve(0,str,n,dp)-1;
}



// Tabulation

#include<bits/stdc++.h>

bool isPalindrome(string &s, int i, int j){
    while(i<=j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}


int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int>dp(n+1,0);
    
    for(int i=n-1;i>=0;i--){
        int minPart = 1e9;
        for(int j=i;j<n;j++){
            if(isPalindrome(str,i,j)){
                int mini = 1+ dp[j+1];
                minPart = min(mini, minPart);
            }
        }
        dp[i] = minPart;
    }
    
    return dp[0]-1;
}

