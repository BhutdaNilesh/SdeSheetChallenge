#include <bits/stdc++.h>

bool checkCycleBFS(int node, vector<int>& vis, vector<vector<int>>& adj){
    queue<pair<int,int>>q;
    q.push({node,-1});
    vis[node] = 1;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int par = x.second;
        int root = x.first;
        
        for(auto it: adj[root]){
            if(!vis[it]){
                q.push({it,root});
                vis[it]=1;
            }else{
                if(par!=it){
                    return true;
                }
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    string y = "Yes";
    string no = "No";
    
    vector<vector<int>>adj(n+1);
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkCycleBFS(i, vis, adj)){
                return y;
            }
        }
    }
    return no;
}
