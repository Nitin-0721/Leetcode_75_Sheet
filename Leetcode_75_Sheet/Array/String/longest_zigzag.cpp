class Solution {
public:
    int maxLen = 0;

    void dfs(TreeNode* root, bool left, int count) {
        if (!root) return;

        maxLen = max(maxLen, count);

        if (left) {
            dfs(root->left, true, 1);             
            dfs(root->right, false, count + 1);   
        } else {
            dfs(root->left, true, count + 1);     
            dfs(root->right, false, 1);           
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxLen;
    }
};