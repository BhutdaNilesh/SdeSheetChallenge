#include<bits/stdc++.h>

void topoDFS(int node, vector<vector<int>>& adj, stack<int>& st, vector<int>& vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            topoDFS(it, adj, st, vis);
        }
    }
    st.push(node);
}

void DFS(int node, vector<vector<int>>& adj, vector<int>& res, vector<int>& vis){
    vis[node]=1;
    res.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            DFS(it, adj, res, vis);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    
    vector<vector<int>>adj(n);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }
   
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoDFS(i, adj, st, vis);
        }
    }
    
    // step2: transpose
    vector<vector<int>>transpose(n);
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto it: adj[i]){
            transpose[it].push_back(i);
        }
    }
    
    vector<vector<int>>ans;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        vector<int>res;
        if(!vis[node]){
            DFS(node, transpose, res,vis);
        }
        ans.push_back(res);
    }
    return ans;
}