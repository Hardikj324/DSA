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
    unordered_map<int,TreeNode*> mp;
    unordered_set<int> child;
public:
    void solver(vector<int> arr) {
        if(!mp.count(arr[0])){
            TreeNode* Node = new TreeNode (arr[0]);
            mp[arr[0]] = Node;
        }
        if(!mp.count(arr[1])){
            TreeNode* Node = new TreeNode(arr[1]);
            mp[arr[1]] = Node;
        }
        child.insert(arr[1]);

        if(arr[2]==1){
            mp[arr[0]]->left = mp[arr[1]];
        }
        else{
            mp[arr[0]]->right = mp[arr[1]];
        }
        return;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();

        for(int i=0;i<n;i++){
            solver(descriptions[i]);
        }

        for(auto x:mp){
            if(!child.count(x.first)){
                return x.second;
            }
        }

        return NULL;
        
    }
};