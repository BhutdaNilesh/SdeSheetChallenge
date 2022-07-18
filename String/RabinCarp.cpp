#include<bits/stdc++.h>

vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int> res;
    int j = 0;
    int pat_size = pat.length();
    for(int i=0; i<str.length(); i++)
    {
        int k = i;
        while(str[k]==pat[j] && j<pat_size)
        {
            k++;
            j++;
        }
        if(j==pat_size)
            res.push_back(i);
        j=0;
    }
    return res;
}