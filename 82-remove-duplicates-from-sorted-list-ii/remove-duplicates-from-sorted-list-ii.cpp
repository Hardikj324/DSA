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
        ListNode* n = new ListNode(0,head);
        ListNode* output = n;
        ListNode* curr = head;

        while(curr!=nullptr){
            if(curr->next !=nullptr && curr->val == curr->next->val){
                while(curr->next !=nullptr && curr->val == curr->next->val ){
                    curr = curr->next;
                }
                output->next = curr->next;
            }
            else{
                output = output->next;
            }
            curr = curr->next;
        }

        return n->next;

    }
};