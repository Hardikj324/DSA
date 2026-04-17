class Solution {
public:
    int reverseNumber(int a) {
        bool negative = a < 0;
        a = abs(a);
        int rev_number = 0;
        while (a > 0) {
            int digit = a % 10;
            rev_number = rev_number * 10 + digit;
            a /= 10;
        }
        return negative ? -rev_number : rev_number;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> ind;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int rev = reverseNumber(nums[i]);

            if (ind.find(nums[i]) != ind.end()) {
                mini = min(i - ind[nums[i]], mini);
            }

            ind[rev] = i;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};