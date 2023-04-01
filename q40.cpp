/*
You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.
*/

#include "headers.h"
using namespace std;

bool isPossible_wrong(vector<int>& nums) {

    vector<pair<int,int> > start_end_indices_subs; // stores start and end indices of all consecutive increasing subsequences

    int sz = nums.size();
    int start = 0;
    for(int i=0;i<nums.size();i++)
    {
        if((i!=sz-1) && (nums[i+1] == nums[i]+1))
            continue;
        else{
            start_end_indices_subs.push_back({start,i});
            start = i+1;
        }
    }    

    int len_of_first_sub = start_end_indices_subs[0].second - start_end_indices_subs[0].first + 1;
    if(len_of_first_sub < 3)
        return false;
    else
    {
        int num_sub = start_end_indices_subs.size();
        for(int i=1;i<num_sub;i++)
        {
            int len_of_sub = start_end_indices_subs[i].second - start_end_indices_subs[i].first + 1; 
            int len_of_prev_sub = start_end_indices_subs[i-1].second - start_end_indices_subs[i-1].first + 1;

            if(len_of_sub<3)
            {
                if(nums[start_end_indices_subs[i].first]!=nums[start_end_indices_subs[i-1].second]+1)
                    return false;
                else
                {
                    if(len_of_sub==1 && len_of_prev_sub>=5)
                    {
                        start_end_indices_subs[i].first = start_end_indices_subs[i-1].second - 1;
                        start_end_indices_subs[i-1].second = start_end_indices_subs[i-1].second - 2;
                    }
                    else if(len_of_sub==2 && len_of_prev_sub>=4)
                    {
                        start_end_indices_subs[i].first = start_end_indices_subs[i-1].second;
                        start_end_indices_subs[i-1].second = start_end_indices_subs[i-1].second - 1;
                    }
                    else
                        return false;
                }

            }
        }
    }
    return true;
}

bool isPossible(vector<int>& nums) {
    int sz = nums.size();
    if(sz<3)
        return false;
    
    unordered_map<int,int> freq; // frequency of each element
    for(int i=0;i<sz;i++)
        freq[nums[i]]++;

    unordered_map<int,int> need; // number of sequences which need first element to complete their sequence

    for(int i=0;i<sz;i++)
    {
        if(freq[nums[i]]==0)
            continue; // no more elements of this type are available
        
        if(need[nums[i]]>0) // some sequences need this element 
        {
            freq[nums[i]]--;
            need[nums[i]]--;
            need[nums[i]+1]++;
        }

        else{
            // try creating a new subsequence of length atleast 3
            if(freq[nums[i]+1]>0 && freq[nums[i]+2]>0)
            {
                freq[nums[i]]--;
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                need[nums[i]+3]++;
            }
            else
                return false;
        }
    }
    return true;
}