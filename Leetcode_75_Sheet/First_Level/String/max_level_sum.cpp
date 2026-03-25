class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 1;

        int maxSum = INT_MIN;
        int bestLevel = 1;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            level++;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                bestLevel = level;
            }
        }

        return bestLevel;
    }
};