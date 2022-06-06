
void dfs(int node, vector<vector<int>>& adj, vector<int>& dfslevel, vector<int>& vis){
    dfslevel.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it, adj, dfslevel, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &ed)
{
    // Write your code here
    vector<vector<int>>ans;
    vector<int>vis(V, 0);
    vector<vector<int>>adj(V);
    for(auto it: ed){ 
        int u = it[0];
        int v = it[1];
//         cout<<u<<" "<<v<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
       
    for(int i=0;i<V;i++){
        vector<int>dfslevel;
        if(!vis[i]){
            dfs(i, adj, dfslevel, vis);
        }
        if(!dfslevel.empty()){
            ans.push_back(dfslevel);
        }
    }
    return ans;
}