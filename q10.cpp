/*
You are given an array pairs, where pairs[i] = [xi, yi], and:

There are no duplicates.
xi < yi
Let ways be the number of rooted trees that satisfy the following conditions:

The tree consists of nodes whose values appeared in pairs.
A pair [xi, yi] exists in pairs if and only if xi is an ancestor of yi or yi is an ancestor of xi.
Note: the tree does not have to be a binary tree.
Two ways are considered to be different if there is at least one node that has different parents in both ways.

Return:

0 if ways == 0
1 if ways == 1
2 if ways > 1
A rooted tree is a tree that has a single root node, and all edges are oriented to be outgoing from the root.

An ancestor of a node is any node on the path from the root to that node (excluding the node itself). The root has no ancestors.
*/

// NOT YET DONE

#include "headers.h"
using namespace std;

// void dfs(int root , vector<vector<int > >& adj,vector<int>& visited , vector<vector<int > >& childcol)
// {
//     visited[root] = 1;
//     for(int i=0 ; i<adj[root].size(); i++)
//     {
//         int neighbour  = adj[root][i];
//         if(visited[neighbour]==0)
//         {
//             childcol[root].push_back(neighbour);
//             dfs(neighbour,adj,visited,childcol);
//         }
//     }
// }

int checkWays(vector<vector<int>>& pairs) 
{
    set<int>node_val; 
    int m = pairs.size();
    for(int j=0;j<m;j++)
    {
        node_val.insert(pairs[j][0]);
        node_val.insert(pairs[j][1]);
    }

    int n = node_val.size();
    // creating adjacency list 
    vector<vector<int > > adj(n,vector<int>());
    for(int j=0;j<m;j++)
    {
        adj[pairs[j][0] - 1].push_back(pairs[j][1] - 1);
        adj[pairs[j][1] - 1].push_back(pairs[j][0] - 1);
    }
    
    // now we have to greedily select the node with max degree , for that we will use a priority queue
    priority_queue< pair<int,int> > pq; // max-heap
    for(int i = 0 ; i < n ; i++)
        pq.push({adj[i].size(),i});
    
    // we also have to select the node with minimum degrees from the nodes already visited
    priority_queue<pair<int,int> ,  vector<pair<int,int> > , greater<pair<int,int > > >visited;

    int multiple = 0;
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int degree = p.first;
        int node = p.second;

        if(!visited.empty())
        {
            pair<int,int> p_ = visited.top();
            int pdegree = p_.first;
            int parent = p_.second;

            // now check if adjecencies of parent contain adjecencies of child , except the parent one ofcourse !!
            for(int i=0;i<degree;i++)
            {
                int el = adj[node][i];
                if(el == parent)
                    continue;
                
                // if el not in adjecency list of parent , then return 0
                if(find(adj[parent].begin(),adj[parent].end(),el) == adj[parent].end())
                    return 0;
            }
            if(pdegree == degree)
            {   
                cout<<pdegree<<endl;
                multiple++;
            }
        }   
        visited.push(p);
    }

    if(multiple)    
        return 2;
    return 1;
}

int main()
{

}