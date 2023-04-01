/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.
*/

#include "headers.h"
using namespace std;

static bool comp(vector<int>& a, vector<int>& b)
{
    if(a[1]==b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int findLongestChain(vector<vector<int>>& pairs) 
{
    int len = pairs.size();
    if (len == 0) return 0;

    sort(pairs.begin(), pairs.end(), comp);
    int res = 1;
    int endtime = pairs[0][1];
    for(int i = 1; i < len; i++)
    {
        if(pairs[i][0] > endtime)
        {
            res++;
            endtime = pairs[i][1];
        }
    }
    return res;
}