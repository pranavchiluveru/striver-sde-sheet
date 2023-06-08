#include <bits/stdc++.h> 
long long merge(long long *arr,int low,int mid,int high)
{
    vector<long long> temp;
    int left=low;
    int right=mid+1;
    long long count=0;
    while(left<=mid&&right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return count;
}
long long mergesort(long long *arr,int low,int high)
{
    long long count=0;
    if(low==high)
        return 0;
    int mid=(low+high)/2;
    count+=mergesort(arr,low,mid);
    count+=mergesort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    /*Method1 TC=O(n2)
    long long count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;i++)
        {
            if(arr[i]>arr[j])
                count+=1;
        }
    }
    return count;
    */
    //Method 2
    return mergesort(arr,0,n-1);


}
