#include<bits/stdc++.h>

bool BlackBox(vector<int>& arr, int n, int k, long long limit){
    int cnt=1;
    long long sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>limit) return false;
        if(arr[i]+sum>limit){
            cnt++;
            sum = arr[i];
        }else{
            sum+=arr[i];
        }
    }
    return cnt<=k;
}
long long ayushGivesNinjatest(int k, int n, vector<int> time) 
{	
	long long low = *max_element(time.begin(),time.end());
    long long high=0;
    for(auto it: time) high+=it;
    long long ans = high;
    
    while(low<=high){
        long long mid = low + (high-low)/2;
        
        if(BlackBox(time, n, k, mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}