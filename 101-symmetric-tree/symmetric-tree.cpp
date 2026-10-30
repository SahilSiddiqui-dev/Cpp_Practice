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
    void invert(TreeNode* root) {
        if(!root) return;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invert(root->left);
        invert(root->right);
    }

    bool same(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return 1;
        if(!r1 || !r2) return 0;
        if(r1->val != r2->val) return 0;

        return same(r1->left, r2->left) && same(r1->right, r2->right); 
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(!root->left || !root->right) return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        invert(left);
        return same(left, right);
    }
};