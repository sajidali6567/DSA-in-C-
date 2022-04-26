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
    bool isValidBST(TreeNode* root) {
        return isValidBstUtil(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBstUtil(TreeNode* root, long l, long r) {
        if(root == NULL ) return true;
        if(l < root->val && root->val < r)
            return isValidBstUtil(root->left, l,  root->val) && isValidBstUtil(root->right, root->val, r);
        return false;
    }
};