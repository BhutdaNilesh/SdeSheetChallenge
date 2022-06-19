// TLE:

#include<bits/stdc++.h>
string kthPermutation(int n, int k) {
    // Write your code here.
    string s;
    for(int i=1;i<=n;i++){
        s+=to_string(i);
    }
    while(k>1){
        next_permutation(s.begin(),s.end());
        k--;
    }
    return s;
}
