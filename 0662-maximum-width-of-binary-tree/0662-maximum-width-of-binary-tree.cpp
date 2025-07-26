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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;  // Change to long long for index
        int ans = 0;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;  // Use long long for min index
            long long first, last;

            for (int i = 0; i < size; i++) {
                long long curIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;

                if (node->left) q.push({node->left, curIndex * 2 + 1});
                if (node->right) q.push({node->right, curIndex * 2 + 2});
            }
            ans = max(ans, (int)(last - first + 1));  // Cast back to int for the final result
        }

        return ans;
    }
};