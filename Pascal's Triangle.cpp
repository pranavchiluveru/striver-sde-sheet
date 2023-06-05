#include <bits/stdc++.h>
vector<long long int> printnthrow(int row)
{
  long long int ans=1;
  vector<long long int> nthrow;
  nthrow.push_back(1);
  for(int col=1;col<row;col++)
  {
    ans=ans*(row-col);
    ans=ans/col;
    nthrow.push_back(ans);
  }
  return nthrow;
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> v;
  for(int i=1;i<=n;i++)
  v.push_back(printnthrow(i));
  return v;
}
