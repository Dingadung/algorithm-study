/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* dummy = l3;
        int sum=0;
        while(l1 != nullptr || l2 != nullptr || sum) {
            if(l1!=nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(sum%10);
            sum/=10;
            l3 = l3->next;
        }
        return dummy->next;
    }
};