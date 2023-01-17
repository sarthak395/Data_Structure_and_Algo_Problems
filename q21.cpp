/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
*/

#include "headers.h"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reorderList_(ListNode* head) 
{
    ListNode* lastnode;
    ListNode* secondlast = head;
    if(secondlast->next==nullptr)
        return secondlast;
    else
    {
        lastnode = secondlast->next;
        if(lastnode->next==nullptr)
            return secondlast;
        else
        {
            while(lastnode->next!=nullptr)
            {
                secondlast = lastnode;
                lastnode = lastnode->next;
            }
        }
    }
    secondlast->next = nullptr;
    lastnode->next = reorderList_(head->next);
    head->next = lastnode; 

    return head;
}

void reorderList_Naive(ListNode* head) 
{
    head = reorderList_(head);
    return;        
}

void reorderList(ListNode* head){
    // use stack to store node pointers from start to end
    stack<ListNode>s;
    ListNode* currnode = head;
    while(currnode!=nullptr)
    {
        s.push(*currnode);
        currnode = currnode->next;
    }

    currnode = head;
    while(!s.empty())
    {
        if(currnode == nullptr)
            break;
        if(s.top() == (const ListNode)(*currnode))
        {
            currnode->next = nullptr;
            break;
        }
        
        s.top().next = currnode->next;
        currnode->next = &s.top();
        currnode = s.top().next;
        s.pop();
    }  
    return; 
}