/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

#include "headers.h"
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> pq;

    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int cur_el = nums[0];
    int count = 0;
    for (int i = 0; i < sz; i++)
    {
        if (cur_el == nums[i])
            count++;
        else
        {
            pq.push({count, cur_el});
            cur_el = nums[i];
            count = 1;
        }
    }
    pq.push({count,cur_el});

    // find top k
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}