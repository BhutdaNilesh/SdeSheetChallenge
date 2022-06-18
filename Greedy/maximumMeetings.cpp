#include <bits/stdc++.h>

bool static cmp(vector<int>& a, vector<int>& b){
    if(a[1]!=b[1]) return a[1]<b[1];
    else return a[2]<b[2];
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<vector<int>>dp(n, vector<int>(3));
    for(int i=0;i<n;i++){
        dp[i][0] = start[i];
        dp[i][1] = end[i];
        dp[i][2] = i+1;
    }
    sort(dp.begin(),dp.end(),cmp);
    vector<int>ans;
    ans.push_back(dp[0][2]);
    int lastend = dp[0][1];
    for(int i=1;i<n;i++){
        if(dp[i][0]>lastend){
            ans.push_back(dp[i][2]);
            lastend = dp[i][1];
        }
    }
    return ans;
}