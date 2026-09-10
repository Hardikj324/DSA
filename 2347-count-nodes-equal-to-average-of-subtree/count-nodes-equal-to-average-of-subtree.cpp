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
    int count = 0;
    pair<int,int> solver(TreeNode* root){
        if(!root)
            return {0, 0};
        auto[lsum,lcount] = solver(root->left);
        auto[rsum,rcount] = solver(root->right);

        int sum = lsum + rsum + root->val;
        int nodes = lcount + rcount + 1;

        if(sum / nodes == root->val)
            count++;

        return {sum, nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        solver(root);
        return count;
    }
};