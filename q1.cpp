/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1)
*/
#include "headers.h"

using namespace std;

int recfunc(int row, int col, vector<vector<int> > matrix, vector<vector<int> >& dp)
{
    int size=matrix[0].size();
    int sum=matrix[row][col];

    // base case
    if(row==size-1){
        return sum;
    }

    // if value known
    if(dp[row][col]!=-1)
        return dp[row][col];
    
    // induction case and value not known
    if(col == 0)
    {
        if(dp[row+1][col]==-1)
            dp[row+1][col]=recfunc(row+1,col,matrix,dp);

        if(dp[row+1][col+1]==-1)
            dp[row+1][col+1]=recfunc(row+1,col+1,matrix,dp);

        dp[row][col] = sum + min(dp[row+1][col],dp[row+1][col+1]);
    }
    else if(col==size-1)
    {
        if(dp[row+1][col]==-1)
            dp[row+1][col]=recfunc(row+1,col,matrix,dp);
            
        if(dp[row+1][col-1]==-1)
            dp[row+1][col-1]=recfunc(row+1,col-1,matrix,dp);

        dp[row][col] = sum + min(dp[row+1][col],dp[row+1][col-1]);
    }
    else
    {
        if(dp[row+1][col]==-1)
            dp[row+1][col]=recfunc(row+1,col,matrix,dp);

        if(dp[row+1][col+1]==-1)
            dp[row+1][col+1]=recfunc(row+1,col+1,matrix,dp);
        
        if(dp[row+1][col-1]==-1)
            dp[row+1][col-1]=recfunc(row+1,col-1,matrix,dp);

        dp[row][col] = sum + min(dp[row+1][col-1],min(dp[row+1][col],dp[row+1][col+1]));
    }
    return dp[row][col];
}

int minFallingPathSum(vector<vector<int> > &matrix)
{
    int size = matrix[0].size();
    vector<vector<int> > dp(size, vector<int>(size,-1));

    int minval = INT32_MAX;
    for(int i=0;i<size;i++){
        minval = min(minval,recfunc(0,i,matrix,dp));
    }
    return minval;
}

int main()
{
    vector<vector<int> > matrix;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> newrow;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            newrow.push_back(x);
        }
        matrix.push_back(newrow);
    }

    cout<<minFallingPathSum(matrix)<<endl;

    return 0;
}