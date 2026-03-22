class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1)
        return {1};
    vector<int> arr;
    vector<int> left = beautifulArray((n + 1) / 2);
    for (int x : left)
    {
        arr.push_back(2 * x - 1);
    }
    vector<int> right = beautifulArray(n / 2);
    for (int x : right)
    {
        arr.push_back(2 * x);
    }
    return arr;
    }
};