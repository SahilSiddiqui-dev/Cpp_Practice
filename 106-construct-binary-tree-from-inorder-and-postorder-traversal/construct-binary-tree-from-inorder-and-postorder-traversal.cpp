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
    int find(vector<int>& inorder, int target, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int &index, int inStart, int inEnd) {
        if(inStart > inEnd) {
            return NULL;
        }

        TreeNode* temp = new TreeNode(postorder[index]);
        int i = find(inorder, postorder[index], inStart, inEnd);
        index--;
        temp->right = tree(inorder, postorder, index, i + 1, inEnd);
        temp->left = tree(inorder, postorder, index, inStart, i - 1);

        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        return tree(inorder, postorder, index, 0, inorder.size() - 1);
    }
};