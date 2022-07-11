#include <bits/stdc++.h>

vector<int>ZAlgorithm(string s, int n, vector<int>&Z){
    int L, R;
    L=R=0;
    for(int i=1;i<n;i++){
        if(i>R){
            L=i;
            R=i;
            while(R<n && s[R-L]==s[R]){
                R++;
            }
            R--;
            Z[i] = R-L+1;
        }else{
            int k = i-L;
            if(Z[k]<R-i+1){
                Z[i]=Z[k];
            }else{
                L=i;
                while(R<n && s[R-L]==s[R]){
                    R++;
                }
                R--;
                Z[i] = R-L+1;
            }
        }
    }
    return Z;
}
int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    int cnt=0;
    string last = p + "$"+s;
    int total = last.length();
    vector<int>Z(total,0);
    ZAlgorithm(last, total, Z);
    
    for(int i=0;i<total;i++){
//         cout<<Z[i]<<" ";
        if(Z[i]==m){
            
            cnt++;
        }
    }
    return cnt;
}