/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
*/

#include "headers.h"
using namespace std;

int triangleNumber(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    int ans=0;
    for(int i = 0; i < n-2; i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            int x = nums[i] + nums[j];
            // binary search to find the index of first element greater than x
            int ind = n;
            int l = j+1, r = n-1;
            while(l <= r)
            {
                int mid = l + (r-l)/2;
                if(nums[mid] < x)
                    l = mid+1;
                else
                {
                    ind = min(ind, mid);
                    r = mid-1;
                }
            }

            ans += ind - j - 1;
        }
    }
    return ans;
}