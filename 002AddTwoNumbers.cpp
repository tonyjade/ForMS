// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Jaden
// Data   : 2016-11-27

/***********************************************************************************************************************
 * 2. Add Two Numbers
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each 
 * of their nodes contain a single digit. Add the two numbers and return it as a linked list. 
 *
 * Example:
 * Input: (1 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 6 -> 0 -> 8
 *
 **********************************************************************************************************************/
#include <iostream>

/*
 * Definition for singly-linked list. 
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {};
};

// The implementation of addTwoNumbers().  
// 1) Set a carry_flag.
// 2) Traverse the two singly-linked lists, while (la || lb || flag), new a memory for the new digit.
// 
// Note: Should not be addTwoNumbers(ListNode* &la, ListNode* &lb)
// What we need are just copies of la and lb, we could not move the header pointers of the two lists.
ListNode* addTwoNumbers(ListNode* la, ListNode* lb)
{
    ListNode *first_node = nullptr, *last_node = nullptr;
    int carry_flag = 0;
    if (!la && !lb)
        return nullptr;
    first_node = new ListNode(0);
    first_node->next = last_node;

    while (la || lb || carry_flag)
    {
        int value = 0;
        if (la)          value += la->val;
        if (lb)          value += lb->val;
        if (carry_flag)  value += 1;
        last_node->next = new ListNode(value % 10);
        last_node = last_node->next;
        carry_flag = (value >= 10)? 1:0; 
    }
    
    return first_node->next;
}

int main()
{
    return 0;
}

