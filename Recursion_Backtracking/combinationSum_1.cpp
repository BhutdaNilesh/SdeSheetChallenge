
// combination sum 1:
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/


// code:
class Solution {
public:
    void solve(int ind, vector<vector<int>>& ans, vector<int>& res, int target, vector<int>& candidates){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(res);
            }
            return;
        }
        
        // pick
        if(candidates[ind]<=target){
            res.push_back(candidates[ind]);
            solve(ind, ans, res, target-candidates[ind],candidates);
            res.pop_back();
        }
        //Not pict
        solve(ind+1, ans, res, target, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(0, ans, res, target, candidates);
        return ans;
    }
};



// Return Subset Sum to K

/*
Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.

*/


// code:

void solve(int ind, vector<vector<int>>&ans, vector<int>& res, vector<int>& arr, int target){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(res);
        }
        return;
    }
    
    // pick

    res.push_back(arr[ind]);
    solve(ind+1, ans, res, arr, target-arr[ind]);
    res.pop_back();

    //Not pick
    solve(ind+1, ans, res, arr, target);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
//     sort(arr.begin(),arr.end());
    vector<int>res;
    solve(0, ans, res, arr, k);
    return ans;
    
}