#include <bits/stdc++.h>

bool checkCycleDFS(int node, int par, vector<int>& vis, vector<vector<int>>& adj){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycleDFS(it, node, vis, adj)){
                return true;
            }
        }else if(par!=it){
            return true;
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
            if(checkCycleDFS(i,-1, vis, adj)){
                return y;
            }
        }
    }
    return no;
}
