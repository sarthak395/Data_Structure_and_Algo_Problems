/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/
#include "headers.h"
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, startindex = 0;
    while (i < n)
    {
        if (i + 2 < n && nums[i] == nums[i + 2])
        {
            int rightmostindex = n;
            int low = i, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == nums[i])
                {
                    rightmostindex = mid;
                    low = mid + 1;
                }
                else if (nums[mid] < nums[i])
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            int numel = rightmostindex - i + 1;
            for (int k = 0; k < 2; k++)
                nums[startindex++] = nums[i];
            i += numel;
        }
        else if (i+1<n && nums[i+1] == nums[i])
        {
            for (int k = 0; k < 2; k++)
                nums[startindex++] = nums[i];
            i += 2;
        }
        else
        {
            nums[startindex++] = nums[i];
            i+=1;
        }
    }
    return startindex;
}