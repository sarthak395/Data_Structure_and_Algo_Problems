/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

#include "headers.h"
using namespace std;

// BRUTE - FORCE APPROACH (GIVES TLE)
int maxArea_1(vector<int>& height) 
{
    int ans = INT32_MIN;
    int sz = height.size();

    for(int i=0;i<sz;i++)
    {
        for(int j=i+1;j<sz;j++)
        {
            ans = max(min(height[i],height[j])*(j-i),ans);
        }
    }
    return ans;        
}

// 2 POINTERS APPROACH
int maxArea_2(vector<int>& height) 
{
    int ans = 0;
    int sz = height.size();
    int i=0,j=sz-1;
    while(i<j)
    {
        ans = max(min(height[i],height[j])*(j-i),ans);
        if(height[i]<height[j])
            i++;
        else if(height[j]<height[i])
            j--;
        else
        {
            i++;
            j--;
        }
    }
    return ans;
}
