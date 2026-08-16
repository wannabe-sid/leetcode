// Approach 1 : Using MaxHeap
// O(n^2 * logk) time and O(k) space
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         int n = arr.size();
//         priority_queue<vector<double>> maxHeap; // maxHeap<fraction, arr[i], arr[j]>
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 double div = (double) arr[i] / arr[j];
//                 maxHeap.push(vector<double>{div, (double)arr[i], (double)arr[j]});
//                 if(maxHeap.size() > k) maxHeap.pop();
//             }
//         }
//         auto vec = maxHeap.top();
//         vector<int> result(2);
//         result[0] = vec[1];
//         result[1] = vec[2];
//         return result;
//     }
// };

// Approach 2 : Using MinHeap
// O(nlogn + klogn) time and O(k) space  
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> minHeap; // minHeap<fraction, i, j>
        for(int i=0; i<n; i++){
            minHeap.push({(double) arr[i] / arr[n - 1], (double) i, (double) (n - 1)});
        }
        int smallest = 1;
        while(smallest < k){
            vector<double> vec = minHeap.top();
            minHeap.pop();
            int i = vec[1];
            int j = vec[2] - 1;
            minHeap.push({(double) arr[i] / arr[j], (double) i, (double) j});
            smallest++;
        }
        vector<double> vec = minHeap.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};
    }
};