int atoi(string str) {
    // Write your code here.
    int sign=1;
    int ind=0;
    int ans=0;
    if(str[ind]=='-'){
        sign=-1;
        ind++;
    }
    
    for(int i=ind;i<str.size();i++){
        if(str[i]<='9' && str[i]>='0'){
            ans = ans*10 + (str[i]-'0');
        }
    }
    return ans*sign;
}