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
    TreeNode* solver(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int posstart,int posend){
        if(instart>inend) return NULL;
        int rootVal = postorder[posend];
        TreeNode* root = new TreeNode(rootVal);

        int i=instart;


        for(;i<=inend;i++){
            if(inorder[i]==rootVal){
                break;
            }
        }
        int leftsize = i - instart;
        int rightsize = inend - i;

        root->left = solver(inorder,postorder,instart,i-1,posstart,posstart+leftsize-1);
        root->right = solver(inorder,postorder,i+1,inend,posend-rightsize,posend-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int end = postorder.size()-1;
        int start = 0;

        return solver(inorder,postorder,start,end,start,end);

        
    }
};