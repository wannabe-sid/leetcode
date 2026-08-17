// Brute Force : O(n * (n + klogk)) time and O(k) space
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
//         int n = quality.size();
//         double result = DBL_MAX;
//         for(int manager=0; manager<n; manager++){
//             double managerRatio = (double) wage[manager] / quality[manager];
//             vector<double> group;
//             for(int worker=0; worker<n; worker++){
//                 double workerWage = (double) managerRatio * quality[worker];
//                 if(workerWage >= wage[worker]){
//                     group.push_back(workerWage);
//                 }
//             }
//             if(group.size() < k) continue;
//             priority_queue<double> maxHeap;
//             double sumWage = 0;
//             for(double& wage : group){
//                 sumWage += wage;
//                 maxHeap.push(wage);
//                 if(maxHeap.size() > k){
//                     sumWage -= maxHeap.top();
//                     maxHeap.pop();
//                 }
//             }
//             result = min(result, sumWage);
//         }
//         return result;
//     }
// };

// Better Solution : O(nlogn + n * (n + klogk)) time and O(n + k) space
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
//         int n = quality.size();
//         double result = DBL_MAX;
//         vector<pair<double, int>> worker_ratio(n); // pair<workerRatio, workerQuality>
//         for(int worker = 0; worker < n; worker++) {
//             worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
//         }
//         sort(begin(worker_ratio), end(worker_ratio));
//         for(int manager = k-1; manager < n; manager++) {    
//             double managerRatio = worker_ratio[manager].first;
//             vector<double> group;
//             for(int worker = 0; worker <= manager; worker++) {
//                 double worker_wage = worker_ratio[worker].second * managerRatio;
//                 group.push_back(worker_wage);
//             }
//             priority_queue<double, vector<double>> pq;
//             double sum = 0;
//             for(double &wage : group) {
//                 sum += wage;
//                 pq.push(wage);

//                 if(pq.size() > k) {
//                     sum -= pq.top();
//                     pq.pop();
//                 }
//             }
//             result = min(result, sum);
//         }
//         return result;
//     }
// };

// Optimal Solution : O(nlogn + klogk + nlogk) time and O(n + k) space
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
//         int n = quality.size();
//         vector<pair<double, int>> worker_ratio(n); // pair<workerRatio, workerQuality>
//         for(int worker = 0; worker < n; worker++) {
//             worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
//         }
//         sort(begin(worker_ratio), end(worker_ratio));
//         priority_queue<int, vector<int>> pq;      
//         double sum_quality = 0;
//         for(int i = 0; i < k; i++) { 
//             pq.push(worker_ratio[i].second); //push all qualities in max-heap
//             sum_quality += worker_ratio[i].second; //Find sum of qualities
//         }
//         double managerRatio = worker_ratio[k-1].first; 
//         double result       = managerRatio * sum_quality;
//         for(int manager = k; manager < n; manager++) {         
//             managerRatio = worker_ratio[manager].first;
//             pq.push(worker_ratio[manager].second); //push all qualities in max-heap
//             sum_quality += worker_ratio[manager].second; //Find sum of qualities
//             if(pq.size() > k) {
//                 sum_quality -= pq.top();
//                 pq.pop();
//             }
//             result = min(result, managerRatio*sum_quality);
//         }
//         return result;
//     }
// };

// Most Optimal Solution : O(nlon + nlogk) time and O(n + k) space
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers(n);
        for(int i = 0; i < n; ++i) {
            double ratio = (double) wage[i] / quality[i];
            workers[i] = {ratio, quality[i]};
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> maxHeap;
        int totalQuality = 0;
        double minCost = DBL_MAX;
        for(int i = 0; i < n; ++i) {
            totalQuality += workers[i].second;
            if(i >= k - 1) {
                minCost = min(minCost, totalQuality * workers[i].first);
            }
            maxHeap.push(workers[i].second);
            if(maxHeap.size() > k - 1) {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return minCost;
    }
};