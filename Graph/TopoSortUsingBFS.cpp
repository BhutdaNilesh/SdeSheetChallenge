#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>topo;
    vector<int>indgree(v,0);
    
    vector<vector<int>>adj(v);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }
    
    for(int i=0;i<v;i++){
        for(auto it: adj[i]){
            indgree[it]++;
        }
    }
    
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indgree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indgree[it]--;
            if(indgree[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}