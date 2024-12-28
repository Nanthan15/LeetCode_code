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
    int maxDepth(TreeNode* root) {
        int lh =0;
        int rh =0;
        if(root==nullptr) return 0;
        //while(root->left==nullptr && root->right==nullptr){
        lh = maxDepth(root->left)+1;
        rh = maxDepth(root->right)+1;
        //}

        return lh>rh?lh:rh;
        
    }
};