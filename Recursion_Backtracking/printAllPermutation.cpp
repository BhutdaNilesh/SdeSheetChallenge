void solve(string res, vector<string>& ans, vector<int>&vis, string& s){
    if(res.size()==s.size()){
        ans.push_back(res);
        return;
    }
    
    for(int i=0;i<s.size();i++){
        if(!vis[i]){
            res+=s[i];
            vis[i] =1;
            solve(res,ans,vis,s);
            vis[i] =0;
            res.pop_back();
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<int>vis(26,0);
    vector<string>ans;
    string res;
    solve(res, ans, vis, s);
    return ans;
}