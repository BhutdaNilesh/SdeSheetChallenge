#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
    map<char,int>mp;
    int i=0,j=0, n = s.size();
    int ans = 0;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==(j-i+1)){
            ans = max(ans, j-i+1);
        }else{
            while(mp.size()<(j-i+1)){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}