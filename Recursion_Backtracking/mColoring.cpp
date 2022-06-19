#include <bits/stdc++.h>

bool isPossible(int node, vector<vector<int>>& mat, vector<int>& color, int prev_col){
    int n = mat.size();
    
    for(int i=0;i<n;i++){
        if(node!=i && mat[i][node]==1 && color[i]==prev_col){
            return false;
        }
    }
    return true;
}

bool solve(int node, int m, vector<vector<int>>& mat, vector<int>& color){
    if(node==mat.size()) return true;
    
    for(int i=1;i<=m;i++){
        if(isPossible(node, mat, color, i)){
            color[node] = i;
            if(solve(node+1, m, mat, color)) return true;
            color[node] = 0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>color(n,0);
    if(solve(0, m, mat, color)) return "YES";
    return "NO";
}