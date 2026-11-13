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
    int find(int target, vector<int>&inorder, int start, int end) {
        for(int i = start ; i <= end; i++) {
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>&inorder, int&index, int Instart, int Inend) {
        if(Instart > Inend) {
            return NULL;
        }

        TreeNode* temp = new TreeNode(preorder[index]);
        int pos = find(preorder[index], inorder, Instart, Inend);
        index++;
        temp->left = build(preorder, inorder, index, Instart, pos - 1);
        
        temp->right = build(preorder, inorder, index, pos + 1, Inend);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {  
        int n = inorder.size() - 1;
        int index = 0;
        return build(preorder, inorder, index, 0, n);
    }
};