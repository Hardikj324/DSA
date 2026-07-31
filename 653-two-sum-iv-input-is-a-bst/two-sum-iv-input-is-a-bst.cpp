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
    unordered_set<int> seen;

    bool solver(TreeNode* root, int k){
        if(root==NULL){
            return false;
        }

        if(seen.count(k-root->val)) return true;
        seen.insert(root->val);

        return solver(root->left,k) || solver(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return solver(root,k);
    }
};