#include<bits/stdc++.h>


int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    
    int n = start.size();
    vector<pair<int,int>>res(n);
    for(int i=0;i<start.size();i++){
        res[i].first = finish[i];
        res[i].second = start[i];
    }
    
    sort(res.begin(),res.end());
//     for(auto it: res){
//         cout<<it.first<<" "<<it.second<<endl;
//     }
    int lastend = res[0].first;
    int laststart = res[0].second;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(res[i].second>=lastend && laststart<res[i].second){
            cnt++;
            lastend = res[i].first;
            laststart = res[i].second;

        }
    }
    
    return cnt;
}