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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* root = ConstructBinaryTree(preorder, inorder, 0, inorder.size()-1, index, root);
        return root;
    }
    TreeNode* ConstructBinaryTree(vector<int>& preorder, vector<int>& inorder, int LI, int RI, int& indexInPreOrder, TreeNode*& root) {
        
        if(LI > RI) return NULL;
        if(LI==RI) {++indexInPreOrder; return NewNode(inorder[LI]);}
        
        int rootKey = preorder[indexInPreOrder];
        root =  NewNode(rootKey);
        // find the Index of rootKey inOrder Array
        int indexOfRootKeyInInorder = find(inorder.begin(), inorder.end(), rootKey)- inorder.begin();
        ++indexInPreOrder;
        root->left = ConstructBinaryTree(preorder, inorder, LI, indexOfRootKeyInInorder-1, indexInPreOrder, root->left);
        root->right = ConstructBinaryTree(preorder, inorder, indexOfRootKeyInInorder+1, RI, indexInPreOrder, root->right);
        return root;
    }
    
    TreeNode* NewNode(int key) {
        TreeNode* temp = new TreeNode();
        temp->val = key;
        temp->left = temp->right = NULL;
        return temp;
    }
};