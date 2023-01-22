/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
*/
#include "headers.h"
using namespace std;

string removeKdigits(string num, int k) 
{
    int n = num.size();
    if(n==k)
        return "0";
    
    stack<char> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && num[i] < st.top() && (n-k) < (st.size() + n - i))
            st.pop();
        
        st.push(num[i]);
    }      

    string rev_ans; 
    
    while(!st.empty())
    {
        rev_ans += st.top();
        st.pop();
    }  
    
    reverse(rev_ans.begin(),rev_ans.end());
    rev_ans = rev_ans.substr(0,n-k);
    int i = 0;
    while(rev_ans[i]=='0')
        i++;
    rev_ans.erase(0,i);
    return (rev_ans!="")?rev_ans:"0";
}