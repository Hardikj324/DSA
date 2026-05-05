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
    int getLength(ListNode* head){
        int count = 0;
        ListNode* list = head;
        while(head !=NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getLength(head);
        if (head == NULL || head->next == NULL || k==0 ) return head;
        k = k%n;

        for(int i=0;i<k;i++){
            ListNode* curr = head;
            ListNode* prev = NULL;
            while(curr->next!=NULL){
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;   // detach last
            curr->next = head;   // attach at front
            head = curr; 
        }
        return head;
    }
};