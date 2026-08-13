class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {nums1[i], nums2[i]};
        }
        auto lambda = [&](auto& p1, auto& p2){
            return p1.second > p2.second;
        };
        sort(begin(vec), end(vec), lambda);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long kSum = 0;
        for(int i=0; i<k; i++){
            kSum += vec[i].first;
            minHeap.push(vec[i].first);
        }
        long long result = kSum * vec[k-1].second;
        for(int i=k; i<n; i++){
            kSum += vec[i].first - minHeap.top();
            minHeap.pop();
            minHeap.push(vec[i].first);
            result = max(result, kSum * vec[i].second);
        }
        return result;
    }
};