// O(nmlogk) time and O(k) space
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int sum = 0;
        vector<vector<int>> result;
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum = nums1[i] + nums2[j];
                if(maxHeap.size() < k){
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                }
                else if(maxHeap.top().first > sum){
                    maxHeap.pop();
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                }
                else{
                    break;
                }
            }
        }
        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
