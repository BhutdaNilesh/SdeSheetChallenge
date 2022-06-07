#include <bits/stdc++.h> 
// Naive approach
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    vector<int>res;
    for(int i=0;i<m;i++){
        res.push_back(arr1[i]);
    }
    for(auto it: arr2){
        res.push_back(it);
    }
    sort(res.begin(),res.end());
    return res;
}




// Better Approach

#include <bits/stdc++.h> 

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	// Write your code here.
   int i=m-1, j=n-1, k = m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k] =nums1[i];
            k--;
            i--;
        }else{
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
    while(i>=0){
        nums1[k]=nums1[i];
        k--;
        i--;
    }
    while(j>=0){
        nums1[k] = nums2[j];
        k--;
        j--;
    }
    return nums1;
}