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
    string res = "~";
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root,path);
        return res;        
    }

    void dfs(TreeNode* root,string path){
        if(!root) return;
        path = char('a'+root->val) +path;
        if(!root->left && !root->right ) res = min(res,path);
        dfs(root->left,path);
        dfs(root->right,path);

    }

};