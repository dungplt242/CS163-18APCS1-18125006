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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 || t2) {
            TreeNode* p = new TreeNode(0);
            if (t1 && t2) {
                p->val = t1->val + t2->val;
                p->left = mergeTrees(t1->left, t2->left);
                p->right = mergeTrees(t1->right, t2->right);
            }
            else if (t1) {
                p->val = t1->val;
                p->left = mergeTrees(t1->left, NULL);
                p->right = mergeTrees(t1->right, NULL);
            }
            else {
                p->val = t2->val;
                p->left = mergeTrees(t2->left, NULL);
                p->right = mergeTrees(t2->right, NULL);
            }
            return p;
        }
        return NULL;
    }
};