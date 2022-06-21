#include<bits/stdc++.h>

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    
    
    string ans;
    bool flag = false;
    int k = arr[0].size();
    for(int i=0;i<k;i++){
        char x = arr[0][i];
        for(int j=0;j<n;j++){
            if(x==arr[j][i]){
                flag = true;
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(x);
        }else{
            break;
        }
    }
    
    return ans;
}



//
#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    sort(arr.begin(),arr.end());
    
    string s1 = arr[0];
    string s2 = arr[n-1];
    string ans;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i]){
            ans.push_back(s1[i]);
        }else{
            break;
        }
    }
    return ans;
}


