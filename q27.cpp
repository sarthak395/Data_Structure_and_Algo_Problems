/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.
*/

#include "headers.h"
using namespace std;

string removeDuplicateLetters(string s) 
{
    int sz = s.size();
    map<char,int> count_of_char;
    map<char,int> visited_char ;       
    for(int i=0;i<sz;i++)
        count_of_char[s[i]]++;

    stack<char>st;
    for(int i=0;i<sz;i++)
    {   
        if(visited_char[s[i]])
            continue;
        while(!st.empty() && st.top() > s[i] && count_of_char[s[i]]>1)
            st.pop();
        
        visited_char[s[i]] = 1;
        st.push(s[i]);
    }

    string rev_ans;
    while(!st.empty())
    {
        rev_ans += st.top();
        st.pop();
    }

    reverse(rev_ans.begin(),rev_ans.end());
    return rev_ans;
}