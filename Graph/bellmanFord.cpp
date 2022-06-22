#include<bits/stdc++.h>

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    
    vector<int>dist(n+1, 1e9);
    dist[src]=0;
    
    for(int i=1;i<n;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    
//     bool flag = false;
//     for(auto it: edges){
//         int u = it[0];
//         int v = it[1];
//         int wt = it[2];
//         if(dist[u]+wt<dist[v]){
// //             cout<<-1<<endl;
//             flag = true;
//             break;
//         }
//     }
//     if(!flag){
//         return dist[dest];
//     }
    return dist[dest];
}