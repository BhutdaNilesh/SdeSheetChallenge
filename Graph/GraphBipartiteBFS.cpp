#include <bits/stdc++.h>

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges.size();
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    
    vector<int>color(n,-1);
    
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            queue<int>q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto it: adj[node]){
                    if(color[it]==-1){
                        q.push(it);
                        color[it] = 1 - color[node];
                    }else if(color[node]==color[it]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}