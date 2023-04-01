/*
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.
*/

#include "headers.h"
using namespace std;

int maximumSwap(int num) {
    // convert num to string
    string s = to_string(num);
    int sz = s.size();
    vector<int>maxi(sz,0); // maxi[i] stores the maximum digit from i to end
    vector<int>pos(sz,0); // pos[i] stores the position of the maximum digit from i to end

    // maxi[sz-1] = s[sz-1]-'0';
    pos[sz-1] = sz-1;
    for(int i=sz-2;i>=0;i--)
    {
        int digit = s[i]-'0';
        if(digit > s[pos[i+1]]-'0')
        {
            // maxi[i] = digit;
            pos[i] = i;
        }
        else
        {
            // maxi[i] = maxi[i+1];
            pos[i] = pos[i+1];
        }
    }

    for(int i=0;i<sz;i++)
    {
        int digit = s[i]-'0';
        // cout<<digit<<" "<<maxi[i]<<endl;
        if(digit < s[pos[i]]-'0') 
        {
            char temp = s[i];
            s[i] = s[pos[i]];
            s[pos[i]] = temp;
            break;
        }
    }
    return stoi(s);
}