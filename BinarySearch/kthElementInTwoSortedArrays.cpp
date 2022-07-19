#include<bits/stdc++.h>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    if(m>n){
        return ninjaAndLadoos(row2,row1,n,m,k);
    }
    
    int low = max(0,k-n), high = min(k,m);
    
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = k - mid1;
        
        int l1 = mid1 == 0 ? INT_MIN : row1[mid1 - 1]; 
        int l2 = mid2 == 0 ? INT_MIN : row2[mid2 - 1];
        int r1 = mid1 == m ? INT_MAX : row1[mid1]; 
        int r2 = mid2 == n ? INT_MAX : row2[mid2]; 
        
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }else if(l1>r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
        
    }
    return 1;
}