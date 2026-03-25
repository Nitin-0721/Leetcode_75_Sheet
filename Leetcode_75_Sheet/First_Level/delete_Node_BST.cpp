TreeNode * deleteNode(TreeNode *root, int key) {
    if (!root) return root;
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } 
    else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (!root->left) {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        TreeNode *temp = root->right;
        while (temp && temp->left) temp = temp->left;
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}