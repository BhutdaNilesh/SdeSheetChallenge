#include<bits/stdc++.h>

double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double t = 1.000000/n;
    double ans  = pow(m,t);
    return ans;
}

// Binary Search

#include<bits/stdc++.h>

double Multiply(double num, int n){
    double ans=1.0;
    for(int i=1;i<=n;i++){
        ans*=num;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double low=1;
    double high = m;
    double exp = 1e-8;
    while((high-low)>exp){
        double mid = low + (high-low)/2;
        if(Multiply(mid, n)>m){
            high = mid;
        }else{
            low = mid;
        }
    }
    return low;
}
