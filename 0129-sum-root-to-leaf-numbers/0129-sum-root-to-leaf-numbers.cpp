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
    int preorder(TreeNode* root , int sum, int val){
        if(root==NULL) return sum;
        val = val * 10 + root->val;
        if(root->left==NULL && root->right==NULL){
            sum += val;
            

            
        }
        
        sum=preorder(root->left,sum,val);
        sum=preorder(root->right,sum,val);

        return sum;
    }
    int sumNumbers(TreeNode* root) {
        return preorder(root,0,0);
        
    }
};