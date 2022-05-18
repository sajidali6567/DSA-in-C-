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
    // we need  maximum of lh + rh for each node
    // Brute force solution O(N^2)
    // so we modified height function to get maximum of lh+rh
    // we are considering height as number of nodes in path
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }
    int height(TreeNode* root, int& maxi) {
        if(root == NULL) return 0;
        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);
        maxi = max(maxi, lh+rh);
        return 1 + max(lh, rh);
    }
};