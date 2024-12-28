/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both are null
        if (!left && !right) return true;
        // One is null, the other is not
        if (!left || !right) return false;
        // Check values and recurse
        return (left->val == right->val) && 
               isMirror(left->left, right->right) && 
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        // Check if the tree is symmetric by comparing left and right subtrees
        return isMirror(root, root);
    }
};