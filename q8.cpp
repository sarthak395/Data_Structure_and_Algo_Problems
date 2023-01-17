/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#include "headers.h"
using namespace std;

int search(vector<int>& nums, int target) 
{
    // first find pivot using binary search
    int n = nums.size();
    int pivotindex= n;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(nums[mid] > nums[n-1])
            low = mid + 1;
        else
        {
            pivotindex = min(pivotindex,mid);
            high= mid -1 ;
        }
    }
    cout << "pivot index is "<<pivotindex <<endl;

    int low = 0 , high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int array_index = (mid + pivotindex)%n;
        if(nums[array_index]==target)
            return array_index;
        else if(nums[array_index] > target)
            high --;
        else
            low++;
    }
    return -1;
}