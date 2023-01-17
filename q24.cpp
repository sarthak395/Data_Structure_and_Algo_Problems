/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
*/

#include "headers.h"
using namespace std;

bool comp(string s1,string s2)
{
    return (s1+s2 > s2+s1);
}

string largestNumber(vector<int>& nums) 
{
    vector<string>strnums;
    int sz = nums.size();

    // handle a small edge case
    bool allzero = true;
    for(int i=0;i<sz;i++)
    {
        if(nums[i]!=0)
        {
            allzero = false;
            break;
        }
    }
    if(allzero)
        return "0";
    for(int i=0;i<sz;i++)
        strnums.push_back(to_string(nums[i]));

    sort(strnums.begin(),strnums.end(),comp);
    string ans;
    for(int i=0;i<sz;i++)
        ans+=strnums[i];
    return ans;
}