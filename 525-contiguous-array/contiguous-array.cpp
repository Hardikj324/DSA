class Solution {
public:
    int findMaxLength(vector<int>& nums) {
            unordered_map<int, int> firstSeen;
    int sum = 0;
    int length = 0;
    firstSeen[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += (nums[i] == 1 ? 1 : -1);
        if (firstSeen.find(sum) != firstSeen.end())
        {
            length = max(length, i - firstSeen[sum]);
        }

        else
        {
            firstSeen[sum] = i;
        }
    }
    return length;
    }
};