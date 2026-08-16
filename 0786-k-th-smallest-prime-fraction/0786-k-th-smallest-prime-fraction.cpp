// Approach 1 : Using MaxHeap
// O(n^2 * logk) time and O(k) space
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>> maxHeap; // maxHeap<fraction, arr[i], arr[j]>
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double div = (double) arr[i] / arr[j];
                maxHeap.push(vector<double>{div, (double)arr[i], (double)arr[j]});
                if(maxHeap.size() > k) maxHeap.pop();
            }
        }
        auto vec = maxHeap.top();
        vector<int> result(2);
        result[0] = vec[1];
        result[1] = vec[2];
        return result;
    }
};

// Approach 2 : Using MinHeap
// O() time and O() space
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         int n = arr.size();
//         priority_queue<vector<double>> maxHeap; // maxHeap<fraction, arr[i], arr[j]>
//     }
// };