/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include "headers.h"
using namespace std;

int strStr(string haystack, string needle) 
{
    int size_need = needle.size();
    int size_hay = haystack.size();

    if(size_need>size_hay)
        return -1;
    
    int start_window = 0;
    for (int i=0;i<size_hay;i++) // i is the last index of window
    {
        if(i-start_window + 1== size_need) // we got the window size
        {
            if(strncmp(&haystack[start_window],&needle[0],size_need)==0)
                return start_window;
            start_window++;
        }
    }
    return -1;
}