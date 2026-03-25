int dfs(TreeNode* root, int maxSoFar){
    if(!root) return 0;

    int count = 0;
    if(root->val >= maxSoFar) count++;
    count += dfs(root->left, max(maxSoFar, root->val));
    count += dfs(root->right, max(maxSoFar, root->val));    
    return count;
}
int goodNodes(TreeNode* root) {
    if(!root) return 0;
    return dfs(root, root->val);
}