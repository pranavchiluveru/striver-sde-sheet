bool searchMatrix(vector<vector<int>>& mat, int target) {
    /*Approach 1 Linear search TC:O(n+m) SC:O(1)
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][mat[0].size()-1]<target)
                continue;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==target)
                    return true;
            }
        }
        return false;
    */
    //Approach 2 :Binary Search TC=O(log(n*m))
    int n=mat.size();
    int m=mat[0].size();
    int low=0,high=n*m-1;
    int mid;
    while(low<=high)
    {
        mid=(low+(high-low)/2);
        if(mat[mid/m][mid%m]==target)
            return true;
        else if(mat[mid/m][mid%m]>target)
            high=mid-1;
        else
            low=mid+1;
    }
    return false;



}
