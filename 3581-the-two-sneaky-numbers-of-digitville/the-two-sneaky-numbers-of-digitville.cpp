class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& arr) {
        int n = *max_element(arr.begin(), arr.end());
    vector<int> a(n + 1, 0);
    vector <int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        a[arr[i]] += 1;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > 1)
        {
            cout << i << endl;
            ans.push_back(i);
        }
    }
    return ans;}
};