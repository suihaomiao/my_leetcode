#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//ListNode是函数，不是一个类；
//第一次遇到这种给定函数的leetcode
ListNode *addTwoNumber(ListNode* l1, ListNode* l2)
{
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int l1_length = 1,l2_length = 1;
    ListNode* p = l1;
    ListNode* q= l2;
    while(p->next != nullptr)
    {
        l1_length++;
        p = p->next;
    }
    while(q->next != nullptr)
    {
        l2_length++;
        q = q->next;
    }
    //如果l1长度小于l2长度
    //将l1补齐
    if(l1_length < l2_length)
    {
        for(int i = 0; i < l2_length - l1_length; i++)
        {
            p->next = new ListNode(0);
            p = p->next;
            //l1->ListNode(0, l1->next);
        }
    }
    else{
        for(int i = 0; i < l1_length - l2_length; i++)
        {
            q->next = new ListNode(0);
            q = q->next;
            //l2->ListNode(0, l2->next);
        }     
    }
    //bool count = false;
    int count = 0;
    ListNode *res = new ListNode(-1);
    ListNode *t = res;
    p = l1;
    q = l2;
    while(q != nullptr && p != nullptr)
    {
        t->next = new ListNode((p->val + q->val + count) % 10);
        //std::cout << t->next->val << std::endl;
        if((p->val + q->val + count) >= 10) count = 1;
        else count = 0;
        std::cout << count << std::endl;
        p = p->next;
        q = q->next;
        t = t->next;
        //std::cout << l1 << std::endl;
    }
    //std::cout << count  << std::endl;
    if(count == 1) 
    {
        t->next = new ListNode(1);
    }
    return res->next;
}
};