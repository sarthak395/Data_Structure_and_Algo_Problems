/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.
*/

#include "headers.h"
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> right(n, -1); // index of just smaller element on right
    vector<int> left(n, -1);  // index of just larger element on left
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && nums[s.top()] > nums[i])
        {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n-1; i > -1; i--)
    {
        while (!s.empty() && nums[s.top()] < nums[i])
        {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    int start1 = -1;
    int end1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (right[i] != -1)
        {
            if (start1 == -1)
            {
                start1 = i;
                end1= right[i];
            }
            else
            {
                end1 = right[i];
            }
        }
    }
    
    
    int start2 = -1;
    int end2=-1;

    for (int i = n-1; i > -1; i--)
    {
        if (left[i] != -1)
        {
            if (start2 == -1)
            {
                start2 = left[i];
                end2 = i;
            }
            else
            {
                start2 = left[i];
            }
        }
    }
    
    if (start1 == -1 && start2 == -1)
        return 0;
    return max(end1,end2)-min(start1,start2);
}