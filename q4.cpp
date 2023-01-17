/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/

#include "headers.h"
using namespace std;

vector<vector<long long>> fourSum(vector<long long> &nums, long long target)
{
    sort(nums.begin(), nums.end());
    long long size = nums.size();
    vector<vector<long long>> ans;
    for (long long i = 0; i < size; i++)
    {
        for (long long j = i + 1; j < size; j++)
        {
            for (long long k = j + 1; k < size; k++)
            {
                long long sum = nums[i] + nums[j] + nums[k];
                // binary search for finding fourth element
                long long low = k + 1, high = size - 1;
                while (low <= high)
                {
                    long long fourth = (low + high) / 2;
                    if (sum + nums[fourth] == target)
                    {
                        while (fourth-1>=0 && nums[fourth - 1] == nums[fourth])
                            fourth--;

                        vector<long long> el{nums[i], nums[j], nums[k], nums[fourth]};
                        ans.push_back(el);

                        while (fourth+1<size && nums[fourth] == nums[fourth + 1])
                        {
                            vector<long long> el_{nums[i], nums[j], nums[k], nums[fourth]};
                            ans.push_back(el_);
                            fourth++;
                        }

                        low  = fourth + 1;
                    }

                    else if (sum + nums[fourth] > target)
                        high = fourth - 1;
                    else
                        low = fourth + 1;
                }
            }
        }
    }

    set<vector<long long > >s;
    for(long long i=0;i<ans.size();i++)
        s.insert(ans[i]);
    ans.clear();
    for (auto it = s.begin(); it != s.end(); it++)
        ans.push_back(*it);
    return ans;
}

long long main()
{
    vector<long long> input;
    long long x;
    cin >> x;
    for (long long i = 0; i < x; i++)
    {
        long long val;
        cin >> val;
        input.push_back(val);
    }
    long long tar;
    cin >> tar;
}
