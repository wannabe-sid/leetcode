// O(nlogn) time and O(1) space
class Solution {
public:
    static bool compareIntervals(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by end times
        sort(intervals.begin(), intervals.end(), compareIntervals); 
        int removals = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) {
                // Overlap detected: remove this interval
                removals++;
            } else {
                // No overlap: keep this interval and update the end bound
                prevEnd = intervals[i][1];
            }
        }
        return removals;
    }
};