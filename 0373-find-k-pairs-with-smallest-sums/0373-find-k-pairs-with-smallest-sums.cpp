// Brute Force
// O(nmlogk) time and O(k) space
// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int sum = 0;
//         vector<vector<int>> result;
//         priority_queue<pair<int, vector<int>>> maxHeap;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 sum = nums1[i] + nums2[j];
//                 if(maxHeap.size() < k){
//                     maxHeap.push({sum, {nums1[i], nums2[j]}});
//                 }
//                 else if(maxHeap.top().first > sum){
//                     maxHeap.pop();
//                     maxHeap.push({sum, {nums1[i], nums2[j]}});
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         while(!maxHeap.empty()){
//             result.push_back(maxHeap.top().second);
//             maxHeap.pop();
//         }
//         return result;
//     }
// };

// Optimal Solution
// min{O(k*log(m*n)), O(k*log(k))} time and O(m*n) space
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int m = nums1.size();
        int n = nums2.size();
        int sum = nums1[0] + nums2[0];
        set<pair<int, int>> visited;
        pq.push({sum, {0, 0}});
        visited.insert({0, 0});
        vector<vector<int>> result;
        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
            // Push (i, j+1) if possible
            if(j+1 < n && visited.find({i, j+1}) == visited.end()){
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
            // Push (i+1, j) if possible
            if(i+1 < m && visited.find({i+1, j}) == visited.end()){
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }
        }
        return result;
    }
};