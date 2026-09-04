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
    TreeNode* prev;;
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root==NULL){
        return  NULL;
      }
      if(root->val == key){
        return helper(root);
      }
    
      TreeNode* dummy = root;
      while(root){
        if(root->val>key){
            if(root->left!=nullptr && root->left->val == key){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else if(root->val<key){
            if(root->right!=nullptr && root->right->val == key){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
      }
      return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(!root->right) return root->left;
        else if(!root->left) return root->right;

        TreeNode* right = root->right;
        TreeNode* left_right = leftmost(root->left);

        left_right->right = right;

        return root->left;
    }

    TreeNode* leftmost(TreeNode* root){
        if(!root->right){
            return root;
        }
        return leftmost(root->right);
    }
};