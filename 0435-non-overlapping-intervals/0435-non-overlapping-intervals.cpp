class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;

        // ✅ Sort by end time (key fix to make it optimal)
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;
        int prevEnd = intervals[0][1]; // end time of last kept interval

        // Pointer scans through intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlap ⇒ remove this one
                removed++;
            } else {
                // No overlap ⇒ keep it and move pointer
                prevEnd = intervals[i][1];
            }
        }

        return removed;
    }
};