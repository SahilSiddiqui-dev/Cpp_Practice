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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>>ans;
        int size;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            size = q.size();
            vector<int>current;
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                current.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(current);
        }
        int n = ans.size() - 1;
        return ans[n][0];
    }
};