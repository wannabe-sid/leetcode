// Brute Force : O(n^2) time and O(1) space
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for (int i = 0; i < n; i++) {
//             if (gas[i] < cost[i]) continue;
//             long currGas = 0;
//             int count = 0;
//             int j = i;
//             while (count < n) {
//                 currGas += gas[j] - cost[j];
//                 if (currGas < 0) break;
//                 j = (j + 1) % n;
//                 count++;
//             }
//             if (count == n) return i;
//         }
//         return -1;
//     }
// };

// Greedy Approach : O(n) time and O(1) space
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalEarned = accumulate(gas.begin(), gas.end(), 0);
        int totalSpent = accumulate(cost.begin(), cost.end(), 0);
        if(totalSpent > totalEarned) return -1;
        int total = 0;
        int resultIdx = 0;
        for(int i=0; i<n; i++){
            total = total + gas[i] - cost[i];
            if(total < 0){
                total = 0;
                resultIdx = i + 1;
            }
        }
        return resultIdx;
    }
};