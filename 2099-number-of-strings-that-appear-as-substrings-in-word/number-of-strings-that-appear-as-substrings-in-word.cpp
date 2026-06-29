class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (auto &x : patterns) {
            if (word.contains(x)) {
                count++;
            }
        }
        return count;
    }
};
