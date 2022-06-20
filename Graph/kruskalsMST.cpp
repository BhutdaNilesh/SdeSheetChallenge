#include<bits/stdc++.h>

bool static cmp(vector<int>&a, vector<int>&b){
    return a[2]<b[2];
}

int findPar(int u, vector<int>& parent){
    if(u==parent[u]) return u;
    else parent[u] = findPar(parent[u],parent);
}

void unionn(int u, int v, vector<int>& parent, vector<int>& rank){
    u = findPar(u, parent);
    v = findPar(v, parent);
    
    if(rank[u]<rank[v]){
        parent[u] = v;
    }else if(rank[v]<rank[u]){
        parent[u] = v;
    }else{
        parent[v] =u;
        rank[u]++;
    }
    
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.

    
    
    sort(graph.begin(),graph.end(), cmp);
    
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    
    vector<int>rank(n+1,0);
    
    int cost=0;
    for(auto it:graph){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(findPar(u, parent) !=findPar(v,parent)){
            cost+=wt;
            unionn(u, v, parent, rank);
        }
    }
    return cost;
}