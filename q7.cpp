/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.
*/
#include "headers.h"
using namespace std;

// priority queue algorith , time complexity => O(nlogk)
int findKthLargest_1(vector<int>& nums, int k) 
{
    int n = nums.size();
    priority_queue<int,vector<int>, greater<int> > que;
    // insert first 'k' numbers in que
    for(int i=0;i<k;i++)
        que.push(nums[i]);
    for(int j=k;j<n;j++)
    {
        if(nums[j] < que.top())
            continue;
        
        else
        {
            que.pop();
            que.push(nums[j]);
        }
    }
    return que.top();
}

// quickselect algorithm , time complexity => O(n) , worst case => O(n^2)

int partition(int l,int r,vector<int>&nums)
{
    int pivot = nums[r]; // our pivot element
    int i=l;
    for(int j=l;j<r;j++)
    {
        if(nums[j]<pivot)
        {
            swap(nums[i],nums[j]);
            i++;
        }
    }
    swap(nums[i],nums[r]);
    return i+1-l;
}
int findKthsmallest(vector<int>& nums, int l,int r,int k) 
{
    if(l>r)
    {
        cout<<"for l="<<l<<" and r="<<r<<endl;
        return -1;
    }
    int pivotel_pos = partition(l,r,nums);
    cout<<pivotel_pos<<"for l="<<l<<" and r="<<r<<"and k is "<<k<<endl;
   
    if(pivotel_pos==k) 
        return nums[pivotel_pos-1+l];
    else if(pivotel_pos < k)
        return findKthsmallest(nums,pivotel_pos,r,k-pivotel_pos);
    else // pivotel_pos > k
        return findKthsmallest(nums,l,pivotel_pos-2,k);
    
}

int findKthLargest(vector<int>& nums, int k) 
{
    return findKthsmallest(nums,0,nums.size()-1,nums.size()-k + 1);
}

int main()
{
     int arr[] = { 7,6,5,4,3,2,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    vector<int> nums(arr, arr + n);

    cout<<findKthLargest(nums,5)<<endl;
}