#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	/*Method 1:Sorting TC=O(nlogn) sc=O(1)
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]==arr[i+1])
			return arr[i];
	}
	*/
	/*Method 2 :hashing TC=O(n) SC=O(n)
	int a[n]={0};
	for(int i=0;i<n;i++)
	{
		a[arr[i]]++;
		if(a[arr[i]]==2)
			return arr[i];
	}
	*/
	//method 3:fast slow pointers TC=O(n) SC=O(1)
	int slow=arr[0];
	int fast=arr[0];
	//first collision
	do{
		slow=arr[slow];
		fast=arr[arr[fast]];
	}while(slow!=fast);
    //to find duplicate do second collision
	fast=arr[0];
	while(slow!=fast)
	{
		slow=arr[slow];
		fast=arr[fast];
	}
	return slow;
}
