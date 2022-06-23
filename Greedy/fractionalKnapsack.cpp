#include <bits/stdc++.h>

// w and v
bool static cmp(pair<int, int>&a, pair<int, int>& b){
    double f1 = double(a.second)/double(a.first);
    double f2 = double(b.second)/double(b.first);
    
    return f1>f2;
}


double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(),cmp);

    double ans=0.0;
    for(int i=0;i<n;i++){

        if(items[i].first<=w){
            w-=items[i].first;
            ans+=items[i].second;
        }else{
            
            double res = ((items[i].second)*w)/(double(items[i].first));
            ans+=res;
            break;
        }
        
    }
    return ans;
}