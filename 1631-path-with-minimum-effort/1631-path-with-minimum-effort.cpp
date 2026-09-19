// Time Complexity: O(NMlogNM) because each cell is pushed and popped from the priority queue at most a constant number of times.
// Space Complexity: O(NM) for effortGrid and the min-heap.
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        vector<vector<int>> effortGrid(n, vector<int>(m, INT_MAX));
        effortGrid[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // priority_queue<pair<effort, pair<row, column>>> q;
        pq.push({0, {0, 0}}); // Push effort 0 and source (0, 0) in queue
        while(!pq.empty()){
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n - 1 && col == m - 1) return effort;
            if(effort > effortGrid[row][col]) continue;
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max(effort, abs(heights[row][col] - heights[nrow][ncol]));
                    if(newEffort < effortGrid[nrow][ncol]) {
                        effortGrid[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                } 
            }
        }
        return 0;
    }
};