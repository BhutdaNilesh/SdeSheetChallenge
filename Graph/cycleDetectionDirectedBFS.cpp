#include <bits/stdc++.h>
// Also known as kahn's algorithm

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int>vis(n+1,0);
    vector<vector<int>>adj(n+1);
    vector<int>indgree(n+1,0);
    
    for(auto it: edges){
        adj[it.first].push_back(it.second);
    }
    for(int i=1;i<=n;i++){
        for(auto it:adj[i]){
            indgree[it]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indgree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it: adj[node]){
            indgree[it]--;
            if(indgree[it]==0){
                q.push(it);
                
            }
        }
    }
    if(cnt==n) return false;
    return true;
}