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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prevnode = nullptr;
        while(temp!=nullptr){
            ListNode* newnode = temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = newnode;
        }
        head = prevnode;

        return head;
    }
};