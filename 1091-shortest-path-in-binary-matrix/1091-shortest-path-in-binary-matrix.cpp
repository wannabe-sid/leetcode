// O(n*m) time and O(n*m) space
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        if (n == 1 && m == 1) return 1;
        int drow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dcol[] = {0, 0, -1, 1, -1, 1, -1, 1};
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        distance[0][0] = 1;
        queue<pair<int, pair<int, int>>> q; // queue<pair<distance, pair<row, column>>> q;
        q.push({1, {0, 0}}); // Push distance 1 and source (0, 0) in queue
        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0; i<8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0 && dist + 1 < distance[nrow][ncol]){
                    distance[nrow][ncol] = 1 + dist;
                    if(nrow == n-1 && ncol == m-1) return dist + 1;
                    q.push({1 + dist, {nrow, ncol}});
                } 
            }
        }
        return -1;
    }
};