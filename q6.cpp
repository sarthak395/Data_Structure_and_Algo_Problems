/*
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.
*/

#include "headers.h"
using namespace std;

string shortestPalindrome(string s) 
{
    int lens = s.size();
    string revs = s;
    reverse(revs.begin(),revs.end());
    for (int i=lens-1;i>=0;i--)
    {
        if(strncmp(&s[0],&revs[lens-i-1],i+1)==0)
            return revs.substr(0,lens-i-1)+s;
    }
}

int main()
{
    string s;
    cin>>s;
    cout<<shortestPalindrome(s)<<endl;
}