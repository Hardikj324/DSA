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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* gtr = new ListNode(0);

        ListNode* ptr1 = less;
        ListNode* ptr2 = gtr;

        ListNode* temp = head;

        while(temp!=nullptr){
        if(temp->val<x){
            ptr1->next = temp;
            ptr1 = temp;
        }
        else{
            ptr2->next = temp;
            ptr2 = temp;
        }

        temp = temp->next;
        }

        ptr2->next = nullptr;
        ptr1->next = gtr->next;

        return less->next;
    }
};