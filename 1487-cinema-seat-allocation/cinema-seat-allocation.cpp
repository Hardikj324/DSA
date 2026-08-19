class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mask; // row -> bitmask of reserved seats

        for (auto& v : reservedSeats) {
            int row = v[0], seat = v[1];
            mask[row] |= (1 << seat); // mark seat as reserved
        }

        int ans = 0;

        for (auto& [row, m] : mask) {
            bool block1 = !(m & ((1<<2)|(1<<3)|(1<<4)|(1<<5)));
            bool block2 = !(m & ((1<<4)|(1<<5)|(1<<6)|(1<<7)));
            bool block3 = !(m & ((1<<6)|(1<<7)|(1<<8)|(1<<9)));

            if (block1 && block3) ans += 2;
            else if (block1 || block2 || block3) ans += 1;
        }

        
        ans += (n - mask.size()) * 2;

        return ans;
    }
};
