#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    vector<int>ans(2);
    
    sort(arr.begin(),arr.end());
    ans[0] = arr[k-1];
    ans[1] = arr[n-k];
    return ans;
}