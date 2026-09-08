// O(m * n) time and O(m * n) space
class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<char>>& board){
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
        board[r][c] = '#';
        dfs(r+1, c, m, n, board);
        dfs(r-1, c, m, n, board);
        dfs(r, c+1, m, n, board);
        dfs(r, c-1, m, n, board);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // Traverse first and last columns
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') dfs(i, 0, m, n, board);
            if(board[i][n-1] == 'O') dfs(i, n-1, m, n, board);
        }
        // Traverse first and last rows
        for(int i=0; i<n; i++){
            if(board[0][i] == 'O') dfs(0, i, m, n, board);
            if(board[m-1][i] == 'O') dfs(m-1, i, m, n, board);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};