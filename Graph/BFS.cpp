#include<bits/stdc++.h>

vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>ans;
    vector<int>vis(V,0);
    vector<vector<int>>adj(V);
    for(auto it: edges){
        int u = it.first;
        int v = it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            queue<int>q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto it: adj[node]){
                    if(vis[it]==0){
                        q.push(it);   
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return ans;
}