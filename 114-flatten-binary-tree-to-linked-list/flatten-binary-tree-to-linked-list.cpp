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
    void solver(TreeNode* root,vector<TreeNode*> &vec){
       if(!root){
        return ;
       }

       vec.push_back(root);
       solver(root->left,vec);
       solver(root->right,vec);

    }
    void flatten(TreeNode* &root) {
        if(!root) return ;
        vector<TreeNode*> vec;
        solver(root,vec);

        int n = vec.size();

        for (int i = 0; i + 1 < vec.size(); i++) {
            vec[i]->left = NULL;
            vec[i]->right = vec[i+1];
        }

        vec.back()->left = NULL;
        vec.back()->right = NULL;
        
    }
};