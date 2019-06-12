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
    bool check(TreeNode* r, TreeNode* l) {
        if (!r && !l) return true;
        if (!r || !l || r->val != l->val) return false;
        return check(r->left, l->right) && check(r->right, l->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->right, root->left);
    }
};