/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // Find the size of the linked list
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        // Helper function to build BST
        return buildBST(head, 0, size - 1);
    }

private:
    TreeNode* buildBST(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Recursively build the left subtree
        int mid = left + (right - left) / 2;
        TreeNode* leftChild = buildBST(head, left, mid - 1);

        // The middle element becomes the root
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;

        // Move to the next node in the list
        head = head->next;

        // Recursively build the right subtree
        root->right = buildBST(head, mid + 1, right);

        return root;
    }
};
