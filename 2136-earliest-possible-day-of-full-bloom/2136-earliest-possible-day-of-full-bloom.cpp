// O(2n + nlogn) time and O(2n) space
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> vec(n); // pair<plantTime[i], growTime[i]>
        for(int i=0; i<n; i++){
            vec[i] = {plantTime[i], growTime[i]};
        }
        auto lambda = [](pair<int, int>& p1, pair<int, int>& p2){
            return p1.second > p2.second;
        };
        sort(vec.begin(), vec.end(), lambda);
        int maxBloomDays = 0;
        int prevPlantDays = 0;
        for(int i=0; i<n; i++){
            int currPlantTime = vec[i].first;
            int currGrowTime  = vec[i].second;
            prevPlantDays += currPlantTime;
            int currBloomTime = prevPlantDays + currGrowTime;
            maxBloomDays = max(maxBloomDays, currBloomTime);
        }
        return maxBloomDays;
    }
};