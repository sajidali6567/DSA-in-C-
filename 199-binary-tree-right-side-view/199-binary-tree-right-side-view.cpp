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
    vector<int> rightSideView(TreeNode* root) {
        // map to store horizontal level and Node
        map<int, int> mp;
        preOrder(root, 0, mp);
        
        vector<int> res;
        for(auto x:mp) {
            res.push_back(x.second);
        }
        return res;
    }
    void preOrder(TreeNode* root, int level, map<int, int>& mp) {
        if(root != NULL) {
            mp[level] =  root->val;
            preOrder(root->left, level+1, mp);
            preOrder(root->right, level+1, mp);
        }
    }
};