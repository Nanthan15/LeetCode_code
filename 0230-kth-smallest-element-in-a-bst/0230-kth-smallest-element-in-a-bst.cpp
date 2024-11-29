/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int inorder(TreeNode* root, int k, int& cnt) {  // Pass cnt by reference
        if (root == nullptr) return -1;  // Handle the base case for recursion

        // Traverse the left subtree
        int left = inorder(root->left, k, cnt);
        if (left != -1) return left;  // If we've found the result in the left subtree, return it

        // Process the current node
        cnt += 1;
        if (cnt == k) return root->val;  // If we are at the k-th smallest node, return its value

        // Traverse the right subtree
        return inorder(root->right, k, cnt);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, k, cnt);
    }
};
