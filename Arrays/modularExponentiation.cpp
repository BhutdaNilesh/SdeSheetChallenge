#include <bits/stdc++.h> 


int modularExponentiation(int x, int n, int m) {
	// Write your code here.
//     x = x%m;
    long long ans=1;
    while(n){
        if(n&1){
            ans = (1LL * ans*x)%m;
        }
        n=n/2;
        x = (1LL*x*x)%m;
    }
    return (ans%m);
}