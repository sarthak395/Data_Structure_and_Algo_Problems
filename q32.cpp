/*
You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
*/

#include "headers.h"
using namespace std;

static bool comparator(vector<int> i1, vector<int> i2)
{
    if(i1[0] == i2[0])
        return i1[1]<i2[1];
    return (i1[0] > i2[0]);
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
{
    sort(people.begin(),people.end(),comparator);
    int num_people = people.size();
    vector<vector<int> > ans;
    
    for(int i=0;i<num_people;i++)
    {
        ans.insert(ans.begin()+ people[i][1],people[i]);
    }
    return ans;
}