class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root != NULL) {
            res.push_back(root->val);  // Add the root value
            vector<int> leftTraversal = preorderTraversal(root->left);  // Traverse left
            vector<int> rightTraversal = preorderTraversal(root->right);  // Traverse right
            
            // Combine left and right traversals
            res.insert(res.end(), leftTraversal.begin(), leftTraversal.end());
            res.insert(res.end(), rightTraversal.begin(), rightTraversal.end());
        }

        return res;
    }
};
