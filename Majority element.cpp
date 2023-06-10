#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int frq=n/2+1;
	/*Hashing TC=O(nlogn) SC=O(n)
	map<int,int> mpp;
	for(int i=0;i<n;i++)
	{
		mpp[arr[i]]++;
	}
	for(auto it:mpp)
	{
		if(it.second>=frq)
			return it.first;
	}
	return -1;

	Approach 2 :sorting
	TC=O(nlogn) SC=O(1)
	sort(arr,arr+n);
	int ele=arr[0];
	int count=1;
	if(n==1)
		return arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]==ele)
		{
			count++;
			if(count==frq)
				return arr[i];
		}
		else
		{
			ele=arr[i];
			count=1;
		}

	}
	return -1;
	*/

	//Best APproach :Moore voting algorithm and verification
	//TC=O(n) SC=O(1)
	int count=0;
	int ele;
	for(int i=0;i<n;i++)//moore algorithm
	{
		if(count==0)
		{
			count=1;
			ele=arr[i];
		}
		else if(ele==arr[i])
		{
			count++;
		}
		else
		{
			count--;

		}
	}
	//moore algorithm over but it doesnt guarentee majority element
	//so we need to do verification
	int c1=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==ele)
			c1++;
		if(c1>=frq)
			return ele;
	}
	return -1;
	
	
}
