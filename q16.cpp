/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

#include "headers.h"
using namespace std;

int mind_rec(int i,int j,string word1,string word2,vector<vector<int > > D)
{
    if(D[i][j]!=-1)
        return D[i][j];
    if(j==0)
        return D[i][j]=i;
    else if(i==0)
        return D[i][j]=j;
    
    
    if(D[i-1][j]==-1)
        D[i-1][j] = mind_rec(i-1,j,word1,word2,D);
    if(D[i-1][j-1]==-1)
        D[i-1][j-1] = mind_rec(i-1,j-1,word1,word2,D);
    if(D[i][j-1]==-1)
        D[i][j-1] = mind_rec(i,j-1,word1,word2,D);

    int min_ = min(D[i-1][j]+1,D[i][j-1]+1);
    if(word1[i-1]==word2[j-1])
        return D[i][j] = min(min_,D[i-1][j-1]);
    else
        return D[i][j] = min(min_,D[i-1][j-1]+1);
}

int minDistance(string word1, string word2) 
{
    int n = word1.size();
    int m = word2.size();

    vector<vector<int> > D(n+1,vector<int>(m+1,-1));
    return mind_rec(n,m,word1,word2,D);
}