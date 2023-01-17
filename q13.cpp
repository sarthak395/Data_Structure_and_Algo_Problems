/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/

#include "headers.h"
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    int m = flights.size();
    // creating adjecency list
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int j = 0; j < m; j++)
        adj[flights[j][0]].push_back({flights[j][1], flights[j][2]}); // {neigh,weight}

    // now apply dijkstra
    vector<int> dist(n, INT32_MAX);
    dist[src] = 0;

    queue<pair<int, pair<int, int>>> pq; // first has dist and second has node , it is a min-heap
    pq.push({0, {0, src}});

    while (!pq.empty())
    {
        int stops = pq.front().first;
        pair<int, int> p = pq.front().second;
        int node = p.second;
        int dist_node = p.first;
        pq.pop();

        if (stops > k)
            continue;

        // relax all the neighbours
        int num_neighbours = adj[node].size();
        for (int j = 0; j < num_neighbours; j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;

            if (dist_node + weight < dist[neighbour])
            {
                dist[neighbour] = dist_node + weight;
                pq.push({stops+1,{dist[neighbour], neighbour}});
            }
        }
    }
    if(dist[dst]==INT32_MAX)
        return -1;
    return dist[dst];
}