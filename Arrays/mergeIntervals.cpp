#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>>ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    for(int i=0;i<n;i++){
        // if ans is empty or new interval is strating
        if(ans.empty() || ans.back()[1]<intervals[i][0]){
            vector<int>res = {intervals[i][0], intervals[i][1]};
            ans.push_back(res);
        }else{
            // updating the end of the interval
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        
    }
    return ans;
}
