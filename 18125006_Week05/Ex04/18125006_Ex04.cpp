/**
 
* Definition for binary tree
 
* struct TreeNode {
 
*     int val;
 
*     TreeNode *left;
 
*     TreeNode *right;
 
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 
* };
 
*/
void find(TreeNode* A, int B, int &temp, int &x) {
    
	if (!A || x!=-1) return;
    
	find(A->left, B, temp, x);
    
	temp++;
    
	if (temp==B) {
        
		x=A->val;
        
		return;
    
	}
    
	find(A->right, B, temp, x);

} 

int Solution::kthsmallest(TreeNode* A, int B) {
    
	int temp=0, x=-1;
    
	find(A, B, temp, x);
    
	return x;

}