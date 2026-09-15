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
    struct Info{
        int min ;
        int max ;
        int sum ;
        bool isBST;
    };

    Info BST(TreeNode* root,int &ans){

        if (root == NULL) {
            return {INT32_MAX, INT32_MIN,0,true};
        }
        
        Info left = BST(root->left,ans);
        Info right = BST(root->right,ans);

        Info curr;

        curr.sum = left.sum + right.sum + root->val;
        curr.isBST = left.isBST && right.isBST && root->val > left.max && root->val < right.min;
        curr.min = min(root->val, left.min);
        curr.max = max(root->val, right.max);

        if(curr.isBST){
            ans = max(curr.sum,ans);
        }
        return curr;

    }
    int maxSumBST(TreeNode* root) {
        int maxsum = 0;
        BST(root, maxsum);
        return maxsum;
    }
};