#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    
    for(int i=0;i<n;i++){
        int low = i+1;
        int high=n-1;
        
        while(low<high){
            if(nums[i]+nums[low]+nums[high]==K){
                ans.push_back({nums[i],nums[low],nums[high]});
                
                int x = nums[low];
                int y = nums[high];
                while(low<high && nums[low]==x){
                    low++;
                }
                while(low<high && nums[high]==y){
                    high--;
                }
            }else if(nums[i]+nums[low]+nums[high]<K){
                low++;
            }else{
                high--;
            }
        }
        while(i+1<n && nums[i]==nums[i+1]){
            i++;
        }
    }
    return ans;
}