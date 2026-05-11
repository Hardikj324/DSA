class Solution {
public:
    int maxDepth(string s) {
        int p = 0;
        int ans = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                p++;
            }
            else if (c == ')')
            {
                p--;
            }
            ans = max(p, ans);
        }
        return ans;
    }
};