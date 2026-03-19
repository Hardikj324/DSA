class Solution {
public:
void reverseArray(vector<int> &nums, int start, int end)
{
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }

}
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
    k = k % (n);
    reverseArray(nums, 0, n - k - 1);
    reverseArray(nums, n - k, n - 1);
    reverseArray(nums, 0, n - 1);
    for (int z = 0; z < n; z++)
    {
        cout << nums[z] << " ";
    }
    cout << endl;
    }
};