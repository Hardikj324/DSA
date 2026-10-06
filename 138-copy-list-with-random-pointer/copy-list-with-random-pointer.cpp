/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* deep = head;
        
        while(deep){
            Node* copy = new Node(deep->val);
            copy->next = deep->next;
            deep->next = copy;
            deep = copy->next;
        }

        deep = head;
        while(deep){
            if(deep->random)
                deep->next->random = deep->random->next;
            deep = deep->next->next; 
        }

        deep = head;
        Node* deep_copy = head->next;
        while(deep){
            Node* copy = deep->next;
            deep->next = copy->next;
            if(copy->next){
                copy->next = copy->next->next;
            }

            deep = deep->next;
        }
        return deep_copy;
    }
};


