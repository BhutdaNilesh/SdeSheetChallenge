int compareVersions(string a, string b) 
{
    // Write your code here
    long long i=0,j=0, aLen = a.length(), bLen = b.length();
    while(i<aLen || j<bLen)
    {
        long long n1 = 0,n2 = 0;
        while(i<aLen && a[i] != '.')
        {
            n1 = n1 * 10 + (a[i] - '0');
            i++;
        }
        while(j<bLen && b[j] != '.')
        {
            n2 = n2*10 + (b[j] - '0');
            j++;
        }
        if(n1 < n2)
            return -1;
        else if(n1 > n2)
            return 1;
        i++;
        j++;
      
    }
      return 0;
}