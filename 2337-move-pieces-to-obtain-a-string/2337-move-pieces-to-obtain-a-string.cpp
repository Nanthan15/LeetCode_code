class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip underscores in `start`
            while (i < n && start[i] == '_') i++;
            // Skip underscores in `target`
            while (j < n && target[j] == '_') j++;

            // Both strings are fully processed
            if (i == n && j == n) return true;

            // If only one string is processed, they can't be the same
            if (i == n || j == n) return false;

            // Characters must match
            if (start[i] != target[j]) return false;

            // Ensure valid movement
            if (start[i] == 'L' && i < j) return false; // 'L' can't move right
            if (start[i] == 'R' && i > j) return false; // 'R' can't move left

            i++;
            j++;
        }

        return true;
    }
};
