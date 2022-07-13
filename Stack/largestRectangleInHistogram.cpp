#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(!st.empty()) ans[i] = st.top();
        st.push(i);
    }
    return ans;
} 

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(!st.empty()) ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangle(vector < int > & heights) {
   // Write your code here.
    int n = heights.size();
    vector<int>next;
    vector<int>prev;
    next = nextSmallerElement(heights, n);
    prev = prevSmallerElement(heights,n);
    int area = -1e9;
    for(int i=0;i<n;i++){
        int l = heights[i];
        if(next[i]==-1){
            next[i] = n;
        }
        int b = next[i]-prev[i]-1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
 }