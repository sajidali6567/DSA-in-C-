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
        map<int, vector<int>> mp;
        Inorder(root, 0, mp);
        return accumulate(mp[mp.size()-1].begin(), mp[mp.size()-1].end(), 0);
    }
    void Inorder(TreeNode* root, int level, map<int, vector<int>>& mp) {
        if(root != NULL) {
            Inorder(root->left, level+1, mp);
            mp[level].push_back(root->val);
            Inorder(root->right, level+1, mp); 
        }  
            
    }
    
};