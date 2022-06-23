#include<bits/stdc++.h>

bool isMatch(char a, char b){
    return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
}


bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
    for(auto it: expression){
        if(it=='(' || it=='[' || it=='{'){
            st.push(it);
        }else if(st.empty()) return false;
        else if(!isMatch(st.top(), it)) return false;
        else st.pop();
    }
    return st.empty();
}