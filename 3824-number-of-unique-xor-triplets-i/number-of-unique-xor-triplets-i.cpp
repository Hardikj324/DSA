class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int m = 1;
        while (m <= n) m <<= 1;
        return m;
    }
};