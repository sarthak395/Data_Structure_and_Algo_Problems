/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique
*/

#include "headers.h"
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
    int sz = gas.size();
    vector<int>left(sz,0) ;
    
    int totalgas = 0,totalcost = 0;
    for(int i=0;i<sz;i++)
    {
        totalcost+= cost[i];
        totalgas += gas[i];
    }
    if(totalcost > totalgas)
        return -1;
    
    int curgas = 0;
    int startpos = 0;
    for(int i=0;i<sz;i++)
    {
        curgas += gas[i] - cost[i];
        if(curgas < 0)
        {
            startpos = i+1;
            curgas = 0;
        }
    }
    return startpos;
}