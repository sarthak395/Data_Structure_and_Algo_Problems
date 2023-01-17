/*
Given two strings s and t of lengths m and n respectively, return the minimum window
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
*/
#include "headers.h"
using namespace std;

string minWindow(string s, string t)
{
    map<char, int> count1;
    int s_sz = s.size();
    int t_sz = t.size();

    for (int i = 0; i < t_sz; i++)
        count1[t[i]]++;

    int minlen = INT32_MAX;
    string ans;

    int count1size = count1.size();

    map<char, int> count2;
    int startwindow = 0;
    int i = 0;
    int enough;
    for (i = 0; i < s_sz; i++)
    {
        count2[s[i]]++;
        // stopping expansion from begining
        while (count2[s[startwindow]] > count1[s[startwindow]])
        {
            startwindow++;
            count2[s[startwindow]]--;
        }
        // stopping expansion from end
        enough = 1;
        map<char, int>::iterator it = count1.begin();
        while (it != count1.end())
        {
            if (count2[it->first] < it->second)
            {
                enough = 0;
                break;
            }
            it++;
        }
        if (enough)
        {
            if (i - startwindow + 1 < minlen)
            {
                ans = s.substr(startwindow, i - startwindow + 1);
                minlen = i - startwindow + 1;
                startwindow = i + 1;
                count2.clear();
                if (startwindow >= s_sz)
                    break;
            }
        }
    }
    if (enough)
    {
        if (i - startwindow + 1 < minlen)
        {
            ans = s.substr(startwindow, i - startwindow + 1);
            minlen = i - startwindow + 1;
            startwindow = i + 1;
            count2.clear();
        }
    }

    return ans;
}