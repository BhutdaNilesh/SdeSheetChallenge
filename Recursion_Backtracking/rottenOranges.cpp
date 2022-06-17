#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int ans=-1;
    int fresh=0;
    int total=0;
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }else if(grid[i][j]==1){
                fresh++;
            }
            if(grid[i][j]!=0){
                total++;
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    while(!q.empty()){
        int size = q.size();
        
        while(size--){
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = it.first + dx[i];
                int ny = it.second + dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                    grid[nx][ny] =2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
        }
        ans++;   
    }
    
    if(fresh>0) return -1;
    if(ans==-1) return 0;
    return ans; 
}



// 

#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int ans=0;
    int total=0;
    int cnt=0;
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            if(grid[i][j]!=0){
                total++;
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    while(!q.empty()){
        int size = q.size();
        cnt+=size;
        while(size--){
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = it.first + dx[i];
                int ny = it.second + dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                    grid[nx][ny] =2;
                    q.push({nx,ny});
                }
            }
        }
        if(!q.empty()) ans++;   
    }
    
    return cnt==total ? ans : -1;
}