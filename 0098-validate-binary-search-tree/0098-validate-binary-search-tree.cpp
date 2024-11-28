class Solution {
public:
    bool check(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true; // A null node is always valid.
        }

        // The current node's value must be within the bounds.
        if (root->val <= lower || root->val >= upper) {
            return false;
        }

        // Recursively check the left and right subtrees with updated bounds.
        return check(root->left, lower, root->val) && check(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        // We use long long to handle integer overflow cases.
        return check(root, LONG_MIN, LONG_MAX);
    }
};
