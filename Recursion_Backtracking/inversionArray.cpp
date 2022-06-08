#include <bits/stdc++.h> 

long long merge(long long* arr, vector<long long>& temp, int s, int mid, int e){
    long long inv_cnt=0;
    int i = s;
    int j = mid;  //as we already passed mid+1
    int k = s;
    
    while(i<=mid-1 && j<=e){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }else{
            temp[k]=arr[j];
            k++;
            j++;
            inv_cnt = inv_cnt + (mid -i);
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    
    for(int i=s;i<=e;i++){
        arr[i] = temp[i];
    }
    return inv_cnt;
}

long long mergeSort(long long *arr, vector<long long>&temp, int s, int e){
    long long mid, inv_cnt=0;
    if(e>s){
        mid = s + (e-s)/2;
        inv_cnt+= mergeSort(arr,temp, s,mid);
        inv_cnt+= mergeSort(arr, temp, mid+1, e);
        
        inv_cnt+= merge(arr,temp, s, mid+1,e);
    }
    return inv_cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    vector<long long>temp(n);
    return mergeSort(arr, temp, 0, n-1);
    
    
}