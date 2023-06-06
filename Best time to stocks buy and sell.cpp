#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    /*naive approch
    int maxprofit=0,profit=0;
    for(int i=0;i<prices.size()-1;i++)
    {
        for(int j=i+1;j<prices.size();j++)
        {
            profit=prices[j]-prices[i];
            if(profit>maxprofit)
                maxprofit=profit;
        }
    }
    return maxprofit;
    */
    //Best approach-kadanes algorithm
    int maxprofit=0,minprice=prices[0],profit;
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]<minprice)
            minprice=prices[i];
        profit=prices[i]-minprice;
        if(profit>maxprofit)
            maxprofit=profit;
    }
    return maxprofit;

}
