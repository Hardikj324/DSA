class Solution {
public:

    bool isLocalMax(ListNode* prev, ListNode* curr, ListNode* next) {
        if (!prev || !next) return false;

        return (curr->val > prev->val &&
                curr->val > next->val);
    }

    bool isLocalMin(ListNode* prev, ListNode* curr, ListNode* next) {
        if (!prev || !next) return false;

        return (curr->val < prev->val &&
                curr->val < next->val);
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* curr = head->next;
        ListNode* prev = head;

        vector<int> critical_points;

        int i = 1;

        while(curr->next) {

            if(isLocalMin(prev, curr, curr->next)) {
                critical_points.push_back(i);
            }
            else if(isLocalMax(prev, curr, curr->next)) {
                critical_points.push_back(i);
            }

            i++;
            curr = curr->next;
            prev = prev->next;
        }


        if(critical_points.size() < 2) {
            return {-1, -1};
        }

        int min_d = INT_MAX;

        for(int i = 0; i < critical_points.size() - 1; i++) {

            int curr_d = critical_points[i + 1]
                       - critical_points[i];

            min_d = min(curr_d, min_d);
        }

        int max_d = critical_points.back()
                  - critical_points.front();

        return {min_d, max_d};
    }
};