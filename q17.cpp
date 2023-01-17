/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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

ListNode* swapPairs(ListNode* head) 
{
    // Base Case
    if(head==nullptr || head->next == nullptr)
        return head;

    ListNode* next_to_head = head->next;
    head->next = swapPairs(next_to_head->next);
    next_to_head->next = head;

    return next_to_head;
}