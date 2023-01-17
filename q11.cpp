/*
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')

Return the simplified canonical path.
*/

#include "headers.h"
using namespace std;

string simplifyPath(string path) 
{
    int lens = path.size();
    int i=0;
    stack<string>filestack;

    while(i<lens)
    {
        while(path[i]=='/')
            i++;
        
        if(i==lens) // for end slashes
            break;
        
        string filename;
        while(i<lens && path[i]!='/')
        {
            filename += path[i];
            i++;
        }
        cout<<filename<<endl;

        if(filename == ".")
            continue;
        else if(filename=="..")
        {
            if(!filestack.empty())
                filestack.pop();
        }
        else
            filestack.push(filename);
    }

    string ans;
    stack<string>filestack2;
    while(!filestack.empty())
    {
        filestack2.push(filestack.top());
        filestack.pop();
    }
    ans = "/";
    while(!filestack2.empty())
    {
        ans += filestack2.top();
        filestack2.pop();
        if(!filestack2.empty()) 
            ans+="/";
    }
    
    return ans;
}