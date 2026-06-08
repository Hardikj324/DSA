/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solver(TreeNode *root, int t, vector<int> temp, vector<vector<int>> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    temp.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr && root->val == t)
    {
        ans.push_back(temp);
        return;
    }

    solver(root->left, t - root->val, temp, ans);
    solver(root->right, t - root->val, temp, ans);
}


vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> temp;

    solver(root, targetSum, temp, ans);

    return ans;
}
};