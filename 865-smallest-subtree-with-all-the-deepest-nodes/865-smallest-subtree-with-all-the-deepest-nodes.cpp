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
    TreeNode* ans;
    int maxDepth = 0;
    int solve(TreeNode* root, int level) {
        if(root == NULL) {
            maxDepth = max(maxDepth, level);
            return level;
        }
        
        int left = solve(root->left, level+1);
        int right = solve(root->right, level+1);
        if(left == right && left == maxDepth) {
            ans = root;
        }
        return max(left, right);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};