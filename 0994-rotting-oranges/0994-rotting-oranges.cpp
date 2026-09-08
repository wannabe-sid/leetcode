// O(m * n) time and O(m * n) space
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 2) q.push({r, c});
                else if(grid[r][c] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        int minutes = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty() && fresh > 0){
            int currLvlSize = q.size();
            minutes++;
            for(int j=0; j<currLvlSize; j++){
                auto [r, c] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return (fresh == 0) ? minutes : -1;
    }
};