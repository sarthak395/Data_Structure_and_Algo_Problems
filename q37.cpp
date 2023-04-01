/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.
*/

#include "headers.h"
using namespace std;

int leastInterval(vector<char>& tasks, int n) 
{
    int len = tasks.size();
    if (len == 0) return 0;
    if (n == 0) return len;

    vector<int> count(26, 0);
    for (int i = 0; i < len; i++)
    {
        count[tasks[i] - 'A']++;
    }

    sort(count.begin(), count.end()); 
    int maxCount = count[25];
    int idleTime = (maxCount - 1) * n;
    for (int i = 24; i >= 0; i--)
    {
        idleTime -= min(count[i], maxCount - 1);
    }

    return idleTime > 0 ? idleTime + len : len;
}