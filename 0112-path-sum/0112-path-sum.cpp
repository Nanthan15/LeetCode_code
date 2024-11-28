class Solution {
public:
    bool check(TreeNode* root, int targetSum, int sum) {
        if (root == nullptr) {
            return false; // Base case: If the current node is null, no path exists.
        }
        
        sum += root->val; // Add current node's value to the sum
        
        // If it's a leaf node, check if the accumulated sum equals the target
        if (root->left == nullptr && root->right == nullptr) {
            return sum == targetSum;
        }
        
        // Recursively check the left and right subtrees
        return check(root->left, targetSum, sum) || check(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum, 0); // Start recursion with initial sum as 0
    }
};
