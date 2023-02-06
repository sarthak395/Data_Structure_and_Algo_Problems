/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/

#include "headers.h"
using namespace std;

static bool comparator(vector<int>&I1 , vector<int>&I2)
{
    if(I1[1]==I2[1])
        return I1[0]<I2[0];
    return I1[1]<I2[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(),intervals.end(),comparator);
    int sz = intervals.size();
    
    int ans = 0;
    int endtime = intervals[0][1];
    for(int i=1;i<sz;i++)
    {
        if(intervals[i][0] < endtime)
            ans++;
        else
            endtime = intervals[i][1];
        
    }
    return ans;
}