// O(k * log(candidates)) time and O(n) space
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> minHeap1, minHeap2;
        long long ans = 0;
        int hired = 0;
        int i = 0;
        int j = n - 1;
        while(hired < k){
            while(minHeap1.size() < candidates && i <= j){
                minHeap1.push(costs[i]);
                i++;
            }
            while(minHeap2.size() < candidates && j >= i){
                minHeap2.push(costs[j]);
                j--;
            }
            int min1 = minHeap1.empty() ? INT_MAX : minHeap1.top();
            int min2 = minHeap2.empty() ? INT_MAX : minHeap2.top();
            if(min1 <= min2){
                ans += min1;
                minHeap1.pop();
            }
            else{
                ans += min2;
                minHeap2.pop();
            }
            hired++;
        }
        return ans;
    }
};