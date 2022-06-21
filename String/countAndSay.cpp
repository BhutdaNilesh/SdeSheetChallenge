string writeAsYouSpeak(int n) 
{
	// Write your code here.	
    
    if(n==1) return "1";
    if(n==2) return "11";
    
    string s = "11";
    for(int i=3;i<=n;i++){
        s+="#";
        string temp;
        int cnt=1;
        for(int j=1;j<s.size();j++){
            if(s[j]==s[j-1]){
                cnt++;
            }else{
                temp+=to_string(cnt);
                temp+=s[j-1];
                cnt=1;
            }
        }
        s=temp;
    }
    return s;
}