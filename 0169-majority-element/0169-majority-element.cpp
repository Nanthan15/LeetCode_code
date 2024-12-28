 // For greater<int> to use a max-heap

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        // Step 1: Create a map to count the frequency of each element
        std::unordered_map<int, int> freqMap;

        // Step 2: Count the frequency of each element
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 3: Create a max-heap (priority_queue) based on frequency count
        // We use greater<int> to make it a max heap based on frequency
        std::priority_queue<std::pair<int, int>> maxHeap;

        // Step 4: Push each element and its frequency into the priority queue
        for (const auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        // Step 5: The element at the top of the heap will be the majority element
        return maxHeap.top().second;
    }
};
