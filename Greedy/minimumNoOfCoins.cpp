int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    
    int cnt=0;
    for(int i=8;i>=0;i--){
        int c = amount/coins[i];
        if(c==0) continue;
        else{
            cnt+=c;
            amount = amount%coins[i];
            if(amount==0) break;
        }
    }
    return cnt;
}
