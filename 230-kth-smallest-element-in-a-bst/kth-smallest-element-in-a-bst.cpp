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
    int ans=-1;
    void solver(TreeNode* root,int k){
        if(!root || ans!=-1){
            return;
        }
        solver(root->left,k);
        count++;
        if(count==k){
            ans = root->val;
            return ;
        }
        solver(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        
        solver(root,k);
        return ans;
    }
};