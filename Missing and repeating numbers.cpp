#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	/*approach 1:naive method TC=O(n2) SC=O(n)
	pair<int,int> p;
	int count;
	for(int i=1;i<=n;i++)
	{
		count=0;
		for(int j=0;j<n;j++)
		{
			if(arr[j]==i)
				count++;
			if(count==2)
			{
				p.second=i;
				break;
			}
		}
		if(count==0)
			p.first=i;
		if(p.first &&p.second)
			return p;
	}
	//approach 2 :Hashing:TC=o(n) SC=o(n)
	pair<int,int> p;
	int a[n+1]={0};
	for(int i=0;i<n;i++)
	{	
		a[arr[i]]++;
    }
	for(int i=1;i<=n;i++)
	{
		if(a[i]==2)
		{
			p.second=i;
			
		}
		if(a[i]==0)
		{
			p.first=i;
		}
	}
	return p;
	*/
	//best approach:mathematical
	long long s=(n*(n+1))/2;
	long long s2=(n*(n+1)*(2*n+1))/6;
	long long sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{	
		sum1+=(long long)arr[i];
		sum2+=(long long)arr[i]*(long long)arr[i];

	}
	long long v1=s-sum1;//gives missing number X-repeating number Y
	long long v2=s2-sum2;//gives X^2-Y^2
	v2=v2/v1;//gives X+Y
	long long x=(v1+v2)/2;
	long long y=x-v1;
	return {(int)x,(int)y};
}
