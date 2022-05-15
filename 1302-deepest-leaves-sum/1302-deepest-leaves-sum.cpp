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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        int sum =0, maxLevel = INT_MIN;
        Inorder(root, 0, sum, maxLevel);
        return sum;
    }
    void Inorder(TreeNode* root, int level, int& sum, int& maxLevel) {
        if(root != NULL) {
            Inorder(root->left, level+1, sum, maxLevel);
            if(level > maxLevel) {
                maxLevel = level;
                sum = root->val;
            } else if (level == maxLevel) {
                sum += root->val;
            }
            Inorder(root->right, level+1, sum, maxLevel); 
        }  
            
    }
    
};