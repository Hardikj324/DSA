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
    void solver(ListNode* curr1,ListNode* curr2,ListNode* prev){
        if(curr2==nullptr){
            return ;
        }

        ListNode* temp = curr2->next;

        curr1->next = temp;
        if(prev)
            prev->next = curr2;
        curr2->next = curr1;

        solver(curr1->next, curr1->next ? curr1->next->next : nullptr, curr1);
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* start = head->next;

        solver(head,head->next,nullptr);


        return start;
    }
};