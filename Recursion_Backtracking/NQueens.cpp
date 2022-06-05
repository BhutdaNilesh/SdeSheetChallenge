#include <bits/stdc++.h>

bool isValid(int row, int col, vector<vector<int>>& res, int n){
        
        int col2 = col;
        int row2= row;
        
        while(col>=0){
            if(res[row][col]==1) return false;
            col--;
        }
        
        col = col2;
        while(row>=0 && col>=0){
            if(res[row][col]==1) return false;
            row--;
            col--;
        }
        
        row = row2;
        col = col2;
        
        while(row<n && col>=0){
            if(res[row][col]==1) return false;
            row++;
            col--;
        }
    
        return true;
    }
void solve(int col,vector<vector<int>>& res, vector<vector<int>>& ans, int n){
        if(col==n){
            vector<int>p;
            for(auto it: res){
                for(auto i: it){
                    p.push_back(i);
                }
            }
            ans.push_back(p);
            return;
        }
        
        for(int row = 0;row<n;row++){
            if(isValid(row, col, res, n)){
                res[row][col] = 1;
                solve(col+1, res, ans, n);
                res[row][col] = 0;
                
            }
        }
    }

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>ans;
        
    vector<vector<int>>res(n,vector<int>(n,0));
        
    solve(0, res, ans, n);
    return ans;
}