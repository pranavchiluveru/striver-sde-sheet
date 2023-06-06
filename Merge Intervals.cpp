#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    //time complexity:o(nlogn)+o(n)
    vector<vector<int>> ans;
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<n;i++)
    {
        int start=intervals[i][0];
        int end=intervals[i][1];
        for(int j=i+1;j<n;j++)
        {
          if (intervals[j][0]<=end) 
          {
              end=max(end,intervals[j][1]);
              i=j;
          } 
          else
          {
            break;
          }
        }
        ans.push_back({start,end});
    }
    return ans;

}
