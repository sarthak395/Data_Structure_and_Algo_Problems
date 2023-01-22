/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
*/

#include "headers.h"
using namespace std;

bool increasingTriplet(vector<int>& nums) 
{
    int smallest = 0;
    int secondsmallest = -1;

    int sz = nums.size();
    for(int i=0;i<sz;i++)
    {
        if(nums[i]<=nums[smallest])
            smallest = i;
        else if(secondsmallest==-1 || nums[i]<=nums[secondsmallest])
            secondsmallest = i;
        else
            return true;
    }        
    return false;
}