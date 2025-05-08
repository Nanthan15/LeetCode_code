class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (head == nullptr) return nullptr;

        unordered_set<int> mp(nums.begin(), nums.end()); // using set for presence check

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (mp.find(cur->val) != mp.end()) {
                prev->next = cur->next;
                
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
