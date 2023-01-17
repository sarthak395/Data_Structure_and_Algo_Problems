/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
*/

#include "headers.h"
using namespace std;

typedef pair<int,pair<int,int> > queel;
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
{
    int nums1sz = nums1.size();
    int nums2sz = nums2.size();

    priority_queue<queel,vector<queel>,greater<queel> >pq;

    vector<vector<int> > ans;
    vector<pair<int,int> > ansind;
    pq.push({nums1[0]+nums2[0],{0,0}});

    while(k && !pq.empty())
    {
        queel el= pq.top();
        pq.pop();

        if(!ansind.empty() && el.second == ansind.back())
            continue;

        int i=el.second.first;
        int j=el.second.second;
        ans.push_back({nums1[i],nums2[j]});
        ansind.push_back({i,j});

        if(i+1 < nums1sz)
            pq.push({nums1[i+1]+nums2[j],{i+1,j}});
        if(j+1 < nums2sz)
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        k--;
    }     
    return ans;   
}