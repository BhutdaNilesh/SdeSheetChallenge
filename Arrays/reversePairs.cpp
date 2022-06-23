#include <bits/stdc++.h> 

int merge(vector<int>& nums, int low, int mid, int high){
    int total=0;
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && nums[i]>(1ll*2*nums[j])){
            j++;
        }
        total+=(j-(mid+1));
    }
    
    
    vector < int > t;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {

        if (nums[left] <= nums[right]) {
            t.push_back(nums[left++]);
        } else {
            t.push_back(nums[right++]);
        }
    }

    while (left <= mid) {
        t.push_back(nums[left++]);
    }
    while (right <= high) {
        t.push_back(nums[right++]);
    }

    for (int i = low; i <= high; i++) {
        nums[i] = t[i - low];
    }
    return total;
}

int solve(vector<int>& arr, int low, int high){
    if(low>=high) return 0;
    int mid = low + (high-low)/2;
    int pair = solve(arr,low,mid);
    pair+=solve(arr,mid+1,high);
    pair+=merge(arr,low,mid,high);
    return pair;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
    
    return solve(arr,0,n-1);
    
}