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
private:
    int max_sum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        maxGain(root, maxi);
        return maxi;
    }
    int maxGain(TreeNode* root, int& maxi) {
        if(root == NULL ) return 0;
        int maxSumL = max(0, maxGain(root->left, maxi));
        int maxSumR = max(0, maxGain(root->right, maxi));
        maxi = max(maxi, root->val + maxSumL + maxSumR);
        return root->val + max(maxSumL,maxSumR);
    }
};