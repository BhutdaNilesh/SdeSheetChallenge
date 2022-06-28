bool findPattern(string p, string s)
{
    // Write your code here.
    
    auto it = s.find(p);
    if(it==string::npos){
        return false;
    }
    return true;
}