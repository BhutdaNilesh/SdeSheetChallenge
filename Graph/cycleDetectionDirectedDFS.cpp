
bool checkCycleDFS(int node, vector<int>&vis, vector<int>& dfsvis, vector<vector<int>>& adj){
    vis[node]=1;
    dfsvis[node]=1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycleDFS(it, vis, dfsvis, adj)) return true;
        }else if(dfsvis[it]){
            return true;
        }
    }
    dfsvis[node]=0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<vector<int>>adj(n+1);
    for(auto it: edges){
        adj[it.first].push_back(it.second);
    }
    
    vector<int>vis(n+1,0);
    vector<int>dfsvis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkCycleDFS(i, vis, dfsvis, adj)) return true;
        }
    }
    return false;
}