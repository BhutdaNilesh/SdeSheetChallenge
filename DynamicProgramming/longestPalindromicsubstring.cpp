#include<bits/stdc++.h>

string longestPalinSubstring(string s)
{
    // Write your code here.
    
    int n = s.size();
    pair<int,int>p = {0,0};
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;j++,i++){
            if(g==0){
                dp[i][j] = true;
            }else if(g==1){
                if(s[i]==s[j]){
                    dp[i][j] = true;
                }
            }else{
                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j] = true;
                }
            }
            if(dp[i][j]){
                if(abs(i-j)>abs(p.first-p.second)){
                    p.first = i;
                    p.second = j;
                }
            }
        }
    }
    
    string ans;
    for(int i=p.first;i<=p.second;i++){
        ans+=s[i];
    }
    return ans;
}





#include<bits/stdc++.h>
string longestPalinSubstring(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    int maxi = 0;
    int start=0;
    
    for(int i=0 ;i<n; i++) dp[i][i] = 1;
    
    for(int i=1; i<n; i++){
        for(int j= 0; j<n-i; j++){
            
            if(s[i+j] == s[j]){
                if(i == 1){
                    dp[j][i+j] = 1;
                    if(maxi < i){
                        start = j;
                        maxi = i;
                    }
                }
                else if(dp[j+1][i+j-1] == 1){
                    dp[j][i+j] = 1;
                    if(maxi< i){
                        start = j;
                        maxi = i;
                    }
                }
            }
        }
    }
    


    return s.substr(start, maxi+1);
}