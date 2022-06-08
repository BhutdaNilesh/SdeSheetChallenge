#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    unordered_map<int, int>mp;
    for(auto it: arr){
        mp[it]++;
    }
    
    int res = -1;
    for(auto it: mp){
        if(it.second>1){
            res=it.first;
        }
    }
    return res;
}


// Method 2 Tortoise method

#include <bits/stdc++.h> 
int findDuplicate(vector<int> &nums, int n){
	// Write your code here.
    int slow = nums[0];
    int fast = nums[0];
    
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow!=fast);
    
    fast = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
