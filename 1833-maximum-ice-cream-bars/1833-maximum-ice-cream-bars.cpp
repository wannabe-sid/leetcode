// Approach 1 : Greedy
// O(n + nlogn) time and O(1) space
// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         sort(costs.begin(), costs.end());
//         int count = 0;
//         for(int& cost : costs){
//             if(cost > coins) return count;
//             else{
//                 count++;
//                 coins -= cost;
//             }
//         }
//         return count;
//     }
// };

// Approach 2 : Counting Sort
// O(maxCost) time and O(maxCost) space
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(begin(costs), end(costs));
        // count[c] = how many ice creams cost exactly c
        vector<int> count(maxCost + 1, 0);
        for (int cost : costs) count[cost]++;
        int total = 0;
        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] == 0) continue;          
            if (coins < cost) break;            
            // Buy whatever is possible
            int bought = min(count[cost], coins / cost);
            total += bought;
            coins -= bought * cost;
        }        
        return total;
    }
};

// Approach 3 : Recursion
