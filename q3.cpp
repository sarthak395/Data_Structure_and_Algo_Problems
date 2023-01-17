#include "headers.h"
using namespace std;

int isMatchRecursive(string s, string p, int i, int j, vector<vector<int> > dp)
{
    // BASE CASE
    if(i==s.size() && j==p.size())
        return 1;
    
    if(i==s.size())
    {
        while(p[j]=='*')
            j++;
        if(j==p.size())
            return 1;
        else 
            return 0;
    }
    if(j==p.size())
        return 0;

    // DO WE ALREADY KNOW THIS ??
    if (dp[i][j] != -1)
        return dp[i][j];

    // INDUCTION CASE
    if (p[j] == '?' || p[j]==s[i])
    {
        if (dp[i + 1][j + 1] == -1)
            dp[i + 1][j + 1] = isMatchRecursive(s, p, i + 1, j + 1, dp);

        return dp[i][j] = dp[i + 1][j + 1];
    }

    while (p[j] == '*' && (j+1!=p.size() && p[j + 1] == '*')) // multiple '*' have same meaning as single '*'
        j++;
    

    if (p[j] == '*')
    {
        if (dp[i + 1][j] == -1)
            dp[i + 1][j] = isMatchRecursive(s, p, i + 1, j, dp);
        if (dp[i][j + 1] == -1)
            dp[i][j + 1] = isMatchRecursive(s, p, i, j + 1, dp);
        if (dp[i + 1][j + 1] == -1)
            dp[i + 1][j + 1] = isMatchRecursive(s, p, i + 1, j + 1, dp);

        return dp[i][j]=(dp[i+1][j] || dp[i][j+1]||dp[i+1][j+1]);
    }

    return dp[i][j] = 0;
}

// DP Solution - Not so efficient
bool isMatch(string s, string p)
{
    vector<vector<int> > dp(s.size()+1, vector<int>(p.size()+1, -1));
    return (isMatchRecursive(s, p, 0, 0, dp)==1);
}

// Efficient Solution
bool isMatch_(string s, string p)
{
    int i=0,j=0;
    int go_to_pattern_pos=-1,saved_s_pos=-1;

    while(i!=s.size())
    {
        while(p[j]=='*')
        {
            j++;
            go_to_pattern_pos = j;
            saved_s_pos=i;
        }
        
        // check if a match
        if(p[j]=='?' || (s[i]==p[j]))
        {
            i++;
            j++;
        }

        // if not a match  but we have a star to go back to
        else if(go_to_pattern_pos != -1)
        {
            j=go_to_pattern_pos;
            i = saved_s_pos ++ ; 
        }

        // if we dont have a star to go back to 
        else
            return false;
    }
    while(p[j]=='*')
        j++;
    return (j==p.size());
}



int main()
{
    string s,p;
    cin>>s;
    cin>>p;
    
    isMatch(s,p) ? cout<<"True" : cout<<"False";
    cout<<endl;
}