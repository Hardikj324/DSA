class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int low = n - k;  // length of window to leave
        int min_sum = INT_MAX;
        int soa = 0; // sum of array

        int curr = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            curr += cardPoints[r];
            soa += cardPoints[r];

            if (r - l + 1 > low) {
                curr -= cardPoints[l];
                l++;
            }

            if (r - l + 1 == low) {
                min_sum = min(min_sum, curr);
            }
        }

        return soa - min_sum;
    }
};
