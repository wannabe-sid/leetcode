// O(n + nlogn) time and O(1) space
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for(int& cost : costs){
            if(cost > coins) return count;
            else{
                count++;
                coins -= cost;
            }
        }
        return count;
    }
};