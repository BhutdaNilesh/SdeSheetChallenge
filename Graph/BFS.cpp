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
        sort(adj[i].begin(),adj[i].end());
    }
    
    for(int i=0;i<V;i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto it: adj[node]){
                    if(vis[it]==0){
                        vis[it]=1;
                        q.push(it);   
                    }
                }
            }
        }
    }
    return ans;
}


//Using Matrix

// #include<bits/stdc++.h>

// vector<int> BFS(int V, vector<pair<int, int>> edges)
// {
//     // Write your code here
//     vector<vector<int>>mat(V, vector<int>(V,0));
//     for(auto it: edges){
//         int u = it.first;
//         int v = it.second;
//         mat[u][v]=1;
//         mat[v][u]=1;
//     }
//     vector<int>vis(V,0);
//     vector<int>ans;
//     for(int i=0;i<V;i++){
//         if(!vis[i]){
//             queue<int>q;
//             q.push(i);
//             vis[i]=1;
//             while(!q.empty()){
//                 int node = q.front();
//                 q.pop();
//                 ans.push_back(node);
//                 for(int j=0;j<V;j++){
//                     if(mat[node][j]==1 && vis[j]==0){
//                         q.push(j);
//                         vis[j]=1;
//                     }
//                 }
//             }
//         }
//     }

//     return ans;
// }



// #include<bits/stdc++.h>

// vector<int> BFS(int V, vector<pair<int, int>> edges)
// {
//     // Write your code here
//     vector<int>ans;
//     vector<int>vis(V,0);
//     vector<vector<int>>adj(V);
//     for(auto it: edges){
//         int u = it.first;
//         int v = it.second;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
   
    
//     for(int i=0;i<V;i++){
//         if(vis[i]==0){
//             queue<int>q;
//             q.push(i);
//             vis[i] = 1;
//             while(!q.empty()){
//                 int node = q.front();
//                 q.pop();
//                 ans.push_back(node);
//                 for(auto it: adj[node]){
//                     if(vis[it]==0){
//                         q.push(it);   
//                         vis[it]=1;
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }




// #include<bits/stdc++.h>

// vector<int> BFS(int V, vector<pair<int, int>> edges)
// {
//     // Write your code here
//     vector<int>ans;
//     unordered_map<int, bool>vis;
//    unordered_map<int, set<int>>adj;
//     for(auto it: edges){
//         int u = it.first;
//         int v = it.second;
//         adj[u].insert(v);
//         adj[v].insert(u);
//     }
   
    
//     for(int i=0;i<V;i++){
//         if(!vis[i]){
//             queue<int>q;
//             q.push(i);
//             vis[i] = 1;
//             while(!q.empty()){
//                 int node = q.front();
//                 q.pop();
//                 ans.push_back(node);
//                 for(auto it: adj[node]){
//                     if(vis[it]==0){
//                         vis[it]=1;
//                         q.push(it);   
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }