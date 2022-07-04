bool ispossible(vector<int>&positions,int n,int c,int mx)
{
    int rooms=1;
    int placed=positions[0];
    for(int i=1;i<n;i++)
    {
        if(positions[i]-placed>=mx)
        {
            rooms++;
            placed=positions[i];
        }
        if(rooms>=c)
            return true;
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
    // Write your code here
    sort(positions.begin(),positions.end());
    int start=1;
    int end=positions[n-1]-positions[0];
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(ispossible(positions,n,c,mid)==true)
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}