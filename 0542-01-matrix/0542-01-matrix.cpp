// O(n * m) time and O(n * m) space
class Solution {
public:
    void bfs(int n, int m, vector<vector<int>>& visited, vector<vector<int>>& distance, vector<vector<int>>& mat){
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                    distance[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int dist = it.second;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    distance[nr][nc] = dist + 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        bfs(n, m, visited, distance, mat);
        return distance;
    }
};