class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_ize = q.size();

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (i == level_size - 1)
                    result.push_back(node->val);

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return result;
    }
};