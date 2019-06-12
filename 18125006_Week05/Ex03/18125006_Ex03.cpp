/**
 
* Definition for binary tree
 
* struct TreeNode {
 
*     int val;
 
*     TreeNode *left;
 
*     TreeNode *right;
 
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 
* };
 
*/
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
	if (!A && !B) return 1;
    
	if (!A || !B || A->val!=B->val) return 0;
    
	return isSameTree(A->right, B->right) && isSameTree(A->left, B->left);

}
