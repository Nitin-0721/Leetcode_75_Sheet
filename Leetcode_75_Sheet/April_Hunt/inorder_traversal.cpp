class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
    private:
    void solve(TreeNode* root, vector<int>result){
        if(root == nullptr){
            return;
            solve(root->left, result);
            result.push_back(root->val);
            solve(root->right, result);
        }
    }
};