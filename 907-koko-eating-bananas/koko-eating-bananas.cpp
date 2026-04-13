class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r)
        {
            int m = (l + r) / 2;
            long long h = 0;

            for (int pile : piles)
            {
                h = h + (pile + m - 1) / m;    //M-1 bumps up the result of division by 1 so we get ceil of(pile/m)
            }

            if (h <= hours)
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};