#include <bits/stdc++.h> 

// C++ inbuilt function 
//  next_permutation(permutation.begin(),permutation.end());

vector<int> nextPermutation(vector<int> &nums, int n)
{
//      Write your code here.
    int ind1, ind2;
    // step1 : find the index where nums[ind1] < nums[ind1+1]
    for(ind1=n-2;ind1>=0;ind1--){
        if(nums[ind1]<nums[ind1+1]){
            break;
        }
    }
    // edge case: if(ind1<0) 
    if(ind1<0){
        reverse(nums.begin(),nums.end());   
    }else{
        // case 2: find the first indes where nums[ind1] < nums[ind2]
        for(ind2 = n-1;ind2>ind1;ind2--){
            if(nums[ind2]>nums[ind1]){
                break;
            }
        }
        // step3: swap the elements with ind1 and ind2 
        swap(nums[ind1],nums[ind2]);
        // step4: reverse the array coz we want smallest next permutation
        reverse(nums.begin()+ ind1+1, nums.end());
    }  
    return nums;
}