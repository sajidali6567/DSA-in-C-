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
    int widthOfBinaryTree(TreeNode* root) {
        return LevelOrder(root);
    }
    int LevelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int maxWidth = INT_MIN;
        q.push({root, 0});
        while(!q.empty()) {
            int width = q.size();
            int firstIndex = q.front().second;
            int lastIndex = q.back().second;
            maxWidth = max(maxWidth, lastIndex - firstIndex +1);
            pair<TreeNode*, int> temp;
            while(width--) {
                temp = q.front();q.pop();
                if(temp.first->left) q.push({temp.first->left, (long long)(temp.second)*2+1});
                if(temp.first->right) q.push({temp.first->right, (long long)(temp.second)*2+2});
            }   
            
        }
        return maxWidth;
    }
};