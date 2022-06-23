int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt, dt+n);
    int platform=1, ans=1;
    
    int i=1;
    int j=0;
    
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            platform++;
            i++;
        }else if(at[i]>dt[j]){
            platform--;
            j++;
        }
        ans = max(ans, platform);
    }
    return ans;
}