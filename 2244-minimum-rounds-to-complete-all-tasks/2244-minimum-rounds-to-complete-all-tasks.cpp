// O(2n) time and O(n) space
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mpp;
        for(int& task : tasks){
            mpp[task]++;
        }
        int rounds = 0;
        for(auto& it : mpp){
            int count = it.second;
            if(count == 1) return -1;
            rounds += (count + 2) / 3;
        }
        return rounds;
    }
};