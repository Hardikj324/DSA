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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            ListNode* curr = temp->next;
            if(temp->val == curr->val){
                temp->next = temp->next->next;
                delete curr;
            }
            else{
            temp = temp->next;
            }
        }
        return head;
    }
};