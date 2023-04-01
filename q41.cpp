/*
Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.
*/

#include "headers.h"
using namespace std;

bool isPossibleDivide(vector<int>& nums, int k) {
    int sz = nums.size();
    if(sz%k!=0)
        return false;
    sort(nums.begin(),nums.end());

    int num_sub = sz/k;
    unordered_map<int,int> freq;
    for(int i=0;i<sz;i++)
        freq[nums[i]]++;

    for(int i=0;i<sz;i++)
    {
        int start = nums[i];
        if(freq[start]==0)
            continue;
        for(int j=start;j<start+k;j++)
        {
            if(freq[j]==0)
                return false;
            else
                freq[j]--;
        }
    }
    return true;
}