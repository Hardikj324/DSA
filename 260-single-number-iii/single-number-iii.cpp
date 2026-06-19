class Solution {
public:
    vector<int> singleNumber(vector<int> &nums)
  {
    vector<int> ans;
    int n = nums.size();
    long XOR = 0;
    for (int i = 0; i < n; i++)
    {
      XOR ^= nums[i];
    }
    int rightMost = XOR & -XOR;
    int XOR1 = 0, XOR2 = 0;
    for (int i = 0; i < n; i++)
    {
      if (rightMost & nums[i])
      {
        XOR1 ^= nums[i];
      }
      else if ((rightMost & nums[i]) == 0)
      {
        XOR2 ^= nums[i];
      }
    }
    ans.push_back(XOR1);
    ans.push_back(XOR2);
    sort(ans.begin(), ans.end());
    return ans;
  }
};