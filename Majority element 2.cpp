#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    //Approach 1 :for loops :TC=O(n2) SC=O(1)
    /*Approach 2: Hashing using Map:Tc=o(nlogn) SC=O(n)
    int n=arr.size();
    int frq=n/3+1;
    int ele,count=0;
    vector<int> v;
    map<int,int> mpp;
    for(int i=0;i<n;i++) //O(n)
    {
        mpp[arr[i]]++; //O(logn)
        if(mpp[arr[i]]==frq)
            v.push_back(arr[i]);
        if(v.size()==2)//because max only 2 ele will be there with majority>n/3
            break;
    }
    return v;
    */
    //Approach 3 :Moore voting algorithm and verification
    //TC=O(n) SC=O(1)
    int n=arr.size();
    int frq=n/3+1;
    int ele1,c1=0,ele2,c2=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {   
        if(c1==0 && arr[i]!=ele2)
        {
            c1=1;
            ele1=arr[i];
        }
        else if(c2==0 && arr[i]!=ele1)
        {
            c2=1;
            ele2=arr[i];
        }
        else if(arr[i]==ele1)
            c1++;
        else if(arr[i]==ele2)
            c2++;
        else 
        {
          c1--;
          c2--;
        }
    }
    int d1=0,d2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele1)
            d1++;
        if(arr[i]==ele2)
            d2++;
    }
    if (d1 >= frq) 
      v.push_back(ele1);
    if (d2 >= frq) 
      v.push_back(ele2);
    return v;

}
