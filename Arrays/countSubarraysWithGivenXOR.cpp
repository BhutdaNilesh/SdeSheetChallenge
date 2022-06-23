#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int res=0;
        for(int j=i;j<n;j++){
            res^=arr[j];
            if(res==x) cnt++;
        }
    }
    return cnt;
}