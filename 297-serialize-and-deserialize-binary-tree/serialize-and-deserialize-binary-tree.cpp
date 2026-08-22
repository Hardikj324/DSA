/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    if (!root) return "null";

    string ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        } else {
            ans += "null,";
        }
    }
    return ans;
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if (data == "null") {
        return nullptr;
    }

    vector<string> val;
    stringstream ss(data);
    string token;

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            val.push_back(token);
        }
    }

    TreeNode* root = new TreeNode(stoi(val[0]));

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    int n = val.size();

    while (!q.empty() && i < n) {
        TreeNode* node = q.front();
        q.pop();

        // Left
        if (val[i] != "null") {
            node->left = new TreeNode(stoi(val[i]));
            q.push(node->left);
        }
        i++;

        // Right
        if (i < n && val[i] != "null") {
            node->right = new TreeNode(stoi(val[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));