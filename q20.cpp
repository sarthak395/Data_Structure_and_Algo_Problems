/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.
*/
#include "headers.h"
using namespace std;

int nthUglyNumber(int n) 
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int num = 0;
    pq.push(1);
    for(int i=0;i<n;i++)
    {
        while(num == pq.top())
            pq.pop();
        num = pq.top();
        pq.pop();
        pq.push(num*2);
        pq.push(num*3);
        pq.push(num*5);
    }    
    return num; 
}