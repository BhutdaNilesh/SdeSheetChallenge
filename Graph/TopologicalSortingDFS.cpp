#include <bits/stdc++.h>

void findTopo(int node, vector<vector<int>>& adj, stack<int>& st ,vector<int>& vis ){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            findTopo(it, adj, st, vis);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v);
    stack<int>st;
    vector<int>vis(v,0);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }
    
    for(int i=0;i<v;i++){
        if(!vis[i]){
            findTopo(i, adj, st, vis);
        }
    }
    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    
    return topo;
}