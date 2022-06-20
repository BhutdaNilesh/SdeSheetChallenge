#include<bits/stdc++.h>
bool isPalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i++]!=s[j--]){
            return false;
        }
    }
    return true;
}

void solve(int ind, string s, vector<string>&path, vector<vector<string>>& ans){
    if(ind==s.size()){
        ans.push_back(path);
        return;
    }
    
    for(int i=ind;i<=s.size();i++){
        if(isPalindrome(s,ind,i)){
            path.push_back(s.substr(ind, i-ind+1));
            solve(i+1, s,path, ans);
            path.pop_back();
        }
    }
}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>>ans;
    vector<string>path;
    solve(0, s, path, ans);
    return ans;
}