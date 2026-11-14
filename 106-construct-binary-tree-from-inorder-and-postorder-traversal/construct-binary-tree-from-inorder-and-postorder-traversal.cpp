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
    // int find(vector<int>& inorder, int target, int start, int end) {
    //     for(int i = start; i <= end; i++) {
    //         if(inorder[i] == target){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    unordered_map<int, int>mp;
    TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int &index, int inStart, int inEnd) {
        if(inStart > inEnd) {
            return NULL;
        }

        TreeNode* temp = new TreeNode(postorder[index]);
        int i = mp[postorder[index]];
        index--;
        temp->right = tree(inorder, postorder, index, i + 1, inEnd);
        temp->left = tree(inorder, postorder, index, inStart, i - 1);

        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int index = postorder.size() - 1;
        return tree(inorder, postorder, index, 0, inorder.size() - 1);
    }
};