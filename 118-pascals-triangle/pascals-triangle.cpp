class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            int ans = 1;
            for (int j = 0; j <= i; j++) {
                if (j == 0) ans = 1;
                else ans = ans * (i - j + 1) / j;
                row.push_back(ans);
            }
            triangle.push_back(row);
        }
        return triangle;

    }
};