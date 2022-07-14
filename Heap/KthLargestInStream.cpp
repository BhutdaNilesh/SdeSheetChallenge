#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
        for(auto it: arr){
            pq.push(it);
        }
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
        return pq.top();
    }

};