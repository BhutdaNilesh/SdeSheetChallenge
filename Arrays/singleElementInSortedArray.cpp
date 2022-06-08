#include <bits/stdc++.h>
int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int ans=-1;
    for(int i=0;i<n;i+=2){
        if(arr[i]!=arr[i+1]){
            return arr[i];
        }
    }
    return ans;
}
