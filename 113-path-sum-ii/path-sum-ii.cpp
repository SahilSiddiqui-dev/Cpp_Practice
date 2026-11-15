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
    void pathSum(TreeNode* root, int target, int currentSum, vector<int>&current, vector<vector<int>>&ans) {
        if (!root) return;

        current.push_back(root->val);
        currentSum += root->val;

        if(!root->left && !root->right && target ==  currentSum){
            ans.push_back(current);
        }
        else {
            if(root->left) pathSum(root->left, target,currentSum, current, ans);
            if(root->right) pathSum(root->right, target, currentSum, current, ans);
        }

        current.pop_back();
        currentSum -= root->val;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int currentSum = 0;
        vector<vector<int>>ans;
        vector<int>current;
        pathSum(root, targetSum, currentSum, current, ans);
        return ans;
    }
};