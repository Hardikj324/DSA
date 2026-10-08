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
    void solver(TreeNode* root,vector<string> &result,string curr){
        if(root->left == nullptr && root->right==nullptr){
            string val = to_string(root->val);
            curr+=val;
            result.push_back(curr);
            return ;
        }
        string val = to_string(root->val) + "->";
        curr+=val;
        if(root->left)
            solver(root->left,result,curr);
        if(root->right)
            solver(root->right,result,curr);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string curr = "";
        solver(root,result,curr);
        return result;
    }
};