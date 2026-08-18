// Brute Force : O(n^2) time and O(n) space
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> candies(n, 1);      
//         bool updated = true;
//         while (updated) {
//             updated = false;
//             for (int i = 1; i < n; ++i) {
//                 if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
//                     candies[i] = candies[i - 1] + 1;
//                     updated = true;
//                 }
//             }
//             for (int i = n - 2; i >= 0; --i) {
//                 if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
//                     candies[i] = candies[i + 1] + 1;
//                     updated = true;
//                 }
//             }
//         }
//         return accumulate(candies.begin(), candies.end(), 0);
//     }
// };

// Better Approach : O(n) time and O(n) space
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> candies(n, 1);
//         for (int i = 1; i < n; ++i) {
//             if (ratings[i] > ratings[i - 1])
//                 candies[i] = candies[i - 1] + 1;
//         }
//         for (int i = n - 2; i >= 0; --i) {
//             if (ratings[i] > ratings[i + 1])
//                 candies[i] = max(candies[i], candies[i + 1] + 1);
//         }
//         return accumulate(candies.begin(), candies.end(), 0);
//     }
// };

// Optimal Approach : O(n) time and O(1) space
// Greedy Approach : Using Slope Concept
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        int i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candies += peak;
                i++;
            }
            int valley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                candies += valley;
                i++;
            }
            candies -= min(peak, valley);
        }
        return candies;
    }
};