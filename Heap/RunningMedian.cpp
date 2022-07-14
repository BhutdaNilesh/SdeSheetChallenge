#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
    vector<int>ans;
    priority_queue<int>maxi;
    priority_queue<int, vector<int>, greater<int>>mini;
    if(n==1){
        return {arr[0]};
    }
    maxi.push(arr[0]);
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        int x = arr[i];
        // size is not equal
        if(maxi.size()>mini.size()){
            if(x>maxi.top()){
                mini.push(x);
            }else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(x);
            }
            int res = maxi.top() + mini.top();
            ans.push_back(res/2);

        }else{
            
            if(x<maxi.top()){
                maxi.push(x);
            }else{
                mini.push(x);
                maxi.push(mini.top());
                mini.pop();        
            }
            ans.push_back(maxi.top());
        }
    }
    return ans;
}
