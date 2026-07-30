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
    int solver(TreeNode* root,int curr){
        if(root==NULL){
            
            return curr;
        }

        int lc = solver(root->left,curr + 1);
        int rc = solver(root->right,curr + 1);

        return max(lc,rc);

    }

    int maxDepth(TreeNode* root) {
        return solver(root,0);
    }
};