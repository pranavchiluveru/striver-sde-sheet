#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*naive approach
    long long sum,maxsum=0;
    for(int i=0;i<n;i++)
    { 
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum>maxsum)
                maxsum=sum;
        }
    }
    return maxsum;
    */
    //Best approach-kadanes algorithm
    long long sum=0,maxsum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>maxsum)
            maxsum=sum;
        if(sum<0)
            sum=0;
    }
    return maxsum;
}
