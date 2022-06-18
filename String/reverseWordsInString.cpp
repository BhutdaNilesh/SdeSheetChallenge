#include <bits/stdc++.h>

string reverseString(string s)
{
    // Write your code here.
    
    vector<string>res;
        
    string p;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ') p+=s[i];
        else{
            if(p=="") continue;
            else{
                res.push_back(p);
            }
            p="";
        }
    }

   
   if(p!=""){
        res.push_back(p);
   }
    

    string fans;
    reverse(res.begin(),res.end());
   
    for(auto it: res){
        if(it!=" "){
            fans+=it;
            fans+=" ";
        }
    }
    fans.pop_back();
    return fans;
    
    
}