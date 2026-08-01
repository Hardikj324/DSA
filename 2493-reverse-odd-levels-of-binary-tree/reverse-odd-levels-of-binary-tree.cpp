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
    void solver(TreeNode* left, TreeNode* right, int level) {
        if(!left || !right) return ;

        if(level%2==1){
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }

        solver(left->left,right->right,level+1);
        solver(left->right,right->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr;
        solver(root->left,root->right,1);
        return root;
    }
};