class Solution {
public:
    int findMin(vector<int>& arr) {
        int r = arr.size() - 1;
        int l = 0;
        int m;

        while (l <r)
        {
            m = l + (r - l) / 2;
            if (arr[r] < arr[m])
            {
                l = m + 1;
            }
            else
            {
                r = m; 
            }
        }

        return arr[l];
    }
};