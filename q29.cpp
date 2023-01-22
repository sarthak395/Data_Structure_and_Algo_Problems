/*
Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.
*/

#include "headers.h"
using namespace std;

// NAIVE RECURSIVE SOLUTION
int integerReplacement_rec(int n) 
{
    if(n==0)
        return INT32_MAX;
    if(n==1)
        return 0;
    if(n%2==0)
        return 1+integerReplacement_rec(n/2);
    else
    {
        return 1 + min(integerReplacement_rec(n-1),integerReplacement_rec(n+1));
    }
}

// BETTER SOLUTION USING BIT MANIPULATION
int integerReplacement(int n)
{
    int count = 0;
    while(n!=1)
    {
        while(n%2==0)
        {
            n=n/2;
            count++;
        }
        if(n==1)
            break;
        if(n==3 || (n-1)%4==0)
        {
            n-=1;
            count++;
        }
        else
        {
            n+=1;
            count++;
        }

    }
    return count;
}
