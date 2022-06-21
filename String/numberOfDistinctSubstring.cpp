#include<bits/stdc++.h>

int distinctSubstring(string &word) {
    //  Write your code here.
    set<string>st;
    int n = word.size();
    for(int i=0;i<n;i++){
        string res;
        for(int j=i;j<n;j++){
            res+=word[j];
            st.insert(res);
        }
    }
    int ans = st.size();
    return ans;
}
