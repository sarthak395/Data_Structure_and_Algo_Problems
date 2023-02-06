/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
*/

#include "headers.h"
using namespace std;

static bool comparator(vector<int>&I1 , vector<int>&I2)
{
    if(I1[1]==I2[1])
        return I1[0]<I2[0];
    return I1[1]<I2[1];
}

int findMinArrowShots(vector<vector<int>>& points) 
{
    sort(points.begin(),points.end(),comparator);
    int sz = points.size();
    
    int ans = 1;
    int endtime = points[0][1];
    for(int i=1;i<sz;i++)
    {
        if(points[i][0] > endtime)
        {
            ans++;
            endtime = points[i][1];
        }
        
    }
    return ans;
}