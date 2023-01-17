/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/

#include "headers.h"
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();
    vector<int>left(n,-1);
    vector<int>right(n,n);

    // find just smaller bar index on right
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && heights[i]<heights[s.top()])
        {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())   
        s.pop();
    
    // find just smaller bar index on left
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && heights[i]<heights[s.top()])
        {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // now find areas
    int maxar =-1;
    for(int i=0;i<n;i++)
        maxar =  max(maxar,heights[i]*(right[i]-left[i]-1));
    
    return maxar;
}