/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

#include "headers.h"

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if(nums1.size()<nums2.size())
        return findMedianSortedArrays(nums2,nums1);
    
    // assume nums2 has less elements
    int m = nums1.size();
    int n = nums2.size();

    // apply binary search on cut C2 in nums2
    int low=0,high=2*n;
    while(low<=high)
    {
        int c2 = (low+high)/2;
        int c1 = n + m - c2;

        int l1 = nums1[(c1-1)/2];
        int l2 = nums2[(c2-1)/2];
        int r1 = nums1[c1/2];
        int r2 = nums2[c2/2];

        if(l2 <= r1 && l1<=r2) // found the cut
            return (max(l1,l2)+min(r1,r2))/2;
        else if(l2 > r1)
            high = c2 -1;
        else
            low = c2 + 1;
        
    }
    return -1;
}

int main()
{
}