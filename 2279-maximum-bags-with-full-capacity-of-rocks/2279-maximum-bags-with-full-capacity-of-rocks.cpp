// O(2n + nlogn) time and O(n) space
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> requiredRocks(n);
        for(int i=0; i<n; i++){
            requiredRocks[i] = capacity[i] - rocks[i];
        }
        sort(requiredRocks.begin(), requiredRocks.end());
        int bags = 0;
        for(int i=0; i<n; i++){
            if(additionalRocks >= requiredRocks[i]){
                additionalRocks -= requiredRocks[i];
                bags++;
            }
            else break;
        }
        return bags;
    }
};