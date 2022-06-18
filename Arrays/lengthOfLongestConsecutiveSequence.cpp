#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    
    int maxi=1;
    int cnt=1;
    for(int i=1;i<n;i++){
       if(arr[i]!=arr[i-1]){
           if(arr[i]==arr[i-1]+1){
               cnt++;
//                cout<<cnt<<endl;
             }else{
               maxi = max(maxi, cnt);
               cnt=1;
           }
       }
    }
    return max(maxi, cnt);
}





//

#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    
    map<int,int>mp;
    for(auto it: arr){
        mp[it]++;
    }
    int maxi=0;
    for(auto it: arr){
        if(mp.find(it-1)==mp.end()){
            int curr= it;
            int cnt=1;
            while(mp.find(curr+1)!=mp.end()){
                curr++;
                cnt++;
            }
            
            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}