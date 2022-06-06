#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top=0, right = m, bottom = n, left =0;
    int prev, curr;
    while(top<bottom && left<right){
        
        if(top+1==bottom || left+1==right){
            break;
        }
        
        prev = mat[top+1][left];
        // First row
        for(int i = left;i<right;i++){
            curr = mat[top][i];
            mat[top][i] = prev;
            prev = curr;
        }
        top++;
        
        //Last column
        for(int i=top;i<bottom;i++){
            curr = mat[i][right-1];
            mat[i][right-1] = prev;
            prev = curr;
        }
        right--;
        
        if(top<bottom){
            for(int i=right-1;i>=left;i--){
                curr = mat[bottom-1][i];
                mat[bottom-1][i] = prev;
                prev = curr;
            } 
        }
        bottom--;
        if(left<right){
            for(int i=bottom-1;i>=top;i--){
                curr = mat[i][left];
                mat[i][left] = prev;
                prev = curr;
            }
            
        }
        left++;
    }  

}