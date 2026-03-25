class Solution {
public:
    int dfs(TreeNode* root, long remaining) {
        if (!root)
            return 0;
        int count = 0;
        if (remaining - root->val == 0)
            count++;
        count += dfs(root->left, remaining - root->val);
        count += dfs(root->right, remaining - root->val);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};