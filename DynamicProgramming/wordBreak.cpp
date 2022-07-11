#include<bits/stdc++.h>
bool wordBreak(vector < string > & arr, int n, string & s) {
    vector<bool> dp(s.size()+1, false);
    dp[0] = true; 
    unordered_set<string> dict;

    
    for(auto it : arr) {
        dict.insert(it);
    }

    for(int i = 0; i <= s.size(); i++) {
        for(int j = i+1; j <= s.size(); j++) {
            int len = j - i;
            string sub = s.substr(i, len);

            if(dict.find(sub) != dict.end() && dp[i]) {
                dp[j] = true;
            }    
        }
    }        
    return dp[s.size()];
}