int kthLargest(vector<int>& arr, int size, int k)
{
	// Write your code here.
    
    priority_queue<int>pq;
    for(auto it: arr){
        pq.push(it);
    }
    
    while(k>1){
        pq.pop();
        k--;
    }
    return pq.top();
}


// Method 2:

int kthLargest(vector<int>& arr, int size, int k)
{
	// Write your code here.
    
    priority_queue<int,vector<int>, greater<int>>pq;
    for(auto it: arr){
        pq.push(it);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}