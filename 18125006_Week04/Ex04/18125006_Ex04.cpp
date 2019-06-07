/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isUnivalTree(TreeNode* root) {
        if (root->left && root->right) {
            if (root->val==root->right->val && root->left->val==root->val)
                return isUnivalTree(root->left) && isUnivalTree(root->right);
            return false;
        }
        if (root->left)
        {
            if (root->val==root->left->val)
                return isUnivalTree(root->left);
            return false;
        }
        if (root->right)
        {
            if (root->val==root->right->val)
                return isUnivalTree(root->right);
            return false;
        }
        return true;
    }
};