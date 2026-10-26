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
   
    void solve(TreeNode* root, int targetSum, bool&flag, int&current) {

        if(!root) return;

        current =  current + root->val;

        if(!root->left && !root->right) {
            if(targetSum == current) {
                flag = true;
                return;
            }
        }
        else {
            solve(root->left, targetSum, flag, current);
            solve(root->right, targetSum, flag, current);
        }
        current -= root->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        bool flag = false;
        int current = 0;
        solve(root, targetSum, flag, current);
        return flag;
    }
};