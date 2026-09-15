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

    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;


    void verifyNode(TreeNode* node){
        if(prev==nullptr || (prev->val<node->val)){
            prev = node;
            return;
        }

        if(first==nullptr){
            first = prev;
            second = node;
        }
        else{
            second = node;
        }
    }

    void morrisInorder(TreeNode* root){
            if(!root) return ;

            while(root){
                if(root->left==nullptr){
                    verifyNode(root);
                    root = root->right;
                }
                else{
                    TreeNode* leftChild = root->left;

                    while(leftChild->right!=nullptr && leftChild->right!=root){
                        leftChild = leftChild->right;
                    }

                    if(leftChild->right==nullptr){
                    leftChild->right = root;
                    root=root->left;
                    }
                    else{
                    leftChild->right = nullptr;
                    verifyNode(root);
                    root = root->right;
                    }

                }
            }
    }
    
    void recoverTree(TreeNode* root) {
        morrisInorder(root);
        swap(first->val,second->val);
    }
};