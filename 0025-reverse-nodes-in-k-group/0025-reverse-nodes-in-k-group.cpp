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
    // Reverse linked list between [a, b)
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* prev = nullptr;
        while (a != b) {
            auto nxt = a->next;
            a->next = prev;
            prev = a;
            a = nxt;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode *a = head, *b = head;
        for (int i = 0; i < k; i++) {
            if (!b) return head; // not enough nodes
            b = b->next;
        }
        ListNode* newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};