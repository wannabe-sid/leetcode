// O(nlogn) time and O(k) space
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<int, vector<int>, greater<int>> minHeap;
//         for(int i=0; i<n; i++){
//             minHeap.push(nums[i]);
//             if(minHeap.size() > k) minHeap.pop();
//         }
//         return minHeap.top();
//     }
// };

// Quick Select: Hoare Partition Algorithm
// O(n) time and O(1) space
class Solution {
public:
    int partitionAlgo(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int i = left + 1;
        int j = right;
        while(i <= j){
            if(nums[i] < pivot && nums[j] > pivot){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= pivot) i++;
            if(nums[j] <= pivot) j--;
        }
        swap(nums[left], nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pivotIdx = 0;
        while(true){
            pivotIdx = partitionAlgo(nums, left, right);
            if(pivotIdx == k - 1) break;
            else if(pivotIdx > k - 1) right = pivotIdx - 1;
            else left = pivotIdx + 1;
        }
        return nums[pivotIdx];
    }
};