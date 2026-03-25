TreeNode * BST(TreeNode*root, int val) {
if(!root) return {};
if(root->val == val) return root;
else if(root->val > val) return BST(root->left, val);
else return BST(root->right, val);
}