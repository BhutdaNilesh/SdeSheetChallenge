#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source) {
    // Write your code here.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n,INT_MAX);
    vector<vector<pair<int,int>>>adj(n);
    for(auto it: vec){
        int u = it[0], v = it[1], wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    dist[source]=0;
    pq.push({0, source});
    
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]){
            int nextnode = it.first;
            int nextDistance = it.second;
            if(dist[nextnode] > dist[node] + nextDistance){
                dist[nextnode] = dist[node] + nextDistance;
                pq.push({dist[nextnode], nextnode});
            }
        }
    }
    return dist;
}
