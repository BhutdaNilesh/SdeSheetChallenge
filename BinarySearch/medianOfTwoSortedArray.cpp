#include<bits/stdc++.h>

double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    for(auto it: b){
        a.push_back(it);
    }
    sort(a.begin(),a.end());
    
    int n = a.size();
    if(n%2==1){
        return double(a[n/2]);
    }else{
        int x = n/2;
        int ans = a[x] + a[x-1];
        return (ans)/2.0;
    }
}
