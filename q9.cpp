/*
There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.

You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.

The star sum is the sum of the values of all the nodes present in the star graph.

Given an integer k, return the maximum star sum of a star graph containing at most k edges.
*/
#include "headers.h"
using namespace std;

int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) 
{
    int n = vals.size();
    vector<priority_queue <int, vector<int>, greater<int>> > pqlist; 
    vector<int>sumq;
    
    // each node has a priority queue of its top k neighbours
    for(int i=0;i<n;i++)
    {
        priority_queue <int, vector<int>, greater<int>> q;
        pqlist.push_back(q);
        sumq.push_back(vals[i]);
    }

    // creating adjacency list 
    vector<vector<int > > adj(n,vector<int>());
    int m = edges.size();
    for(int j=0;j<m;j++)
    {
        adj[edges[j][0]].push_back(edges[j][1]);
        adj[edges[j][1]].push_back(edges[j][0]);
    } 

    for (int i=0;i<n;i++)
    {
        // for every node , pick out its top k neighbours
        int num_neighbours = adj[i].size();
        for(int j=0;j<num_neighbours;j++)
        {
            if(vals[adj[i][j]] > 0)
            {
                pqlist[i].push(vals[adj[i][j]]);
                sumq[i] += vals[adj[i][j]];

                if(pqlist[i].size() > k)
                {
                    sumq[i] -= pqlist[i].top();
                    pqlist[i].pop();
                }
            }
        }
    }

    int ans = INT32_MIN;
    for(int j=0;j<n;j++)
        ans = max(ans,sumq[j]);
    return ans;
}