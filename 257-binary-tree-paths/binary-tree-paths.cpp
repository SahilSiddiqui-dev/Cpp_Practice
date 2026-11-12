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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});
        
        while (!q.empty()) {
            auto [node, path] = q.front();
            q.pop();
            
            // If it's a leaf node, add path to result
            if (!node->left && !node->right) {
                result.push_back(path);
            }
            
            // Push left child with updated path
            if (node->left) {
                q.push({node->left, path + "->" + to_string(node->left->val)});
            }
            
            // Push right child with updated path
            if (node->right) {
                q.push({node->right, path + "->" + to_string(node->right->val)});
            }
        }
        
        return result;
    }
};