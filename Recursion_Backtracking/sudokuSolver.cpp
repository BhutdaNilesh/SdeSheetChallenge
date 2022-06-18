#include <bits/stdc++.h>

bool isValid(int matrix[9][9], int row, int col, int x){
    for(int i=0;i<9;i++){
        int nrow = 3*(row/3) + i/3;
        int ncol = 3*(col/3) + i%3;
        
        if(matrix[i][col]==x) return false;
        if(matrix[row][i]==x) return false;
        if(matrix[nrow][ncol]==x) return false;
    }
    return true;
}

bool solve(int matrix[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(isValid(matrix, i, j, k)){
                        matrix[i][j] = k;
                        if(solve(matrix)){
                            return true;
                        }else{
                            matrix[i][j] =0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix);
}
