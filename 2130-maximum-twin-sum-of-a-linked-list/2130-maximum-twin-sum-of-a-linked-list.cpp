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
class Solution {
public:
    // Step 1: Find middle of the linked list using slow and fast pointer
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Step 2: Reverse a linked list
    ListNode* reversenode(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    // Step 3: Traverse original and reversed list to find max twin sum
    int pairSum(ListNode* head) {
        // Get middle and reverse second half
        ListNode* mid = middle(head);
        ListNode* secondHalf = reversenode(mid);

        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = secondHalf;
        while (second) {
            int twinSum = first->val + second->val;
            maxSum = max(maxSum, twinSum);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};
