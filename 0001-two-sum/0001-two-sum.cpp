class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> vec(n);
        int i = 0;
        int j = n-1;
        for(int i=0; i<n; i++){
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());
        while(i < j){
            int sum = vec[i].first + vec[j].first;
            if(sum == target){
                return {vec[i].second, vec[j].second};
            }
            else if(sum < target) i++;
            else j--;
        }
        return {};
    }
};