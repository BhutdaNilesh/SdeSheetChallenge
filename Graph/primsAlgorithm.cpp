#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,int>>adj[n+1];
    
    for(auto it:g){
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    vector<int>parent(n+1,-1);
    vector<int>dist(n+1,INT_MAX);
    vector<bool>mstSet(n+1,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    pq.push({0,1}); // key and index
    dist[1]=0;
    parent[1] = -1;

    
    while(!pq.empty()){


        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for(auto it: adj[u]){
            int node = it.first;
            int wt = it.second;

            if(mstSet[node] == false && wt < dist[node]){
                parent[node] = u;
                dist[node] = wt;
                pq.push({dist[node], node});
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; ++i) {
        ans.push_back({{parent[i], i}, dist[i]});
    }
    
    return ans;
    
}
