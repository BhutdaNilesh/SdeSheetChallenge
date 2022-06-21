#include <bits/stdc++.h>

void solve(int i, int j, vector<vector<int>>& ans, vector<int>&vis, vector<vector<int>>& maze, int n){
    
    if(i==n-1 && j==n-1){
        vis[i*n+j]=1;
        ans.push_back(vis);
        return;
    }
    
    if(i>=n || i<0 || j>=n || j<0 || maze[i][j]==0 || vis[i*n+j]==1){
        return;
    }
    
    vis[i*n+j]=1;
    solve(i+1, j, ans, vis, maze, n);
    solve(i-1, j, ans, vis, maze, n);
    solve(i, j+1, ans, vis, maze, n);
    solve(i, j-1, ans, vis, maze, n);
    vis[i*n+j]=0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>>ans;
    vector<int>vis(n*n,0);
    if(maze[0][0]==1) solve(0,0, ans,vis, maze,n);
    return ans;
}