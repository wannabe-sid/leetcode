// Approach 1
// class Solution {
// public:
//     bool isSafe(int row, int col, vector<string>& board, int n){
//         int duprow = row;
//         int dupcol = col;
//         while(row >= 0 && col >= 0){
//             if(board[row][col] == 'Q') return false;
//             row--;
//             col--;
//         }
//         row = duprow;
//         col = dupcol;
//         while(col >= 0){
//             if(board[row][col] == 'Q') return false;
//             col--;
//         }
//         row = duprow;
//         col = dupcol;
//         while(row < n && col >= 0){
//             if(board[row][col] == 'Q') return false;
//             row++;
//             col--;
//         }
//         return true;
//     }
//     void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row=0; row<n; row++){
//             if(isSafe(row, col, board, n)){
//                 board[row][col] = 'Q';
//                 solve(col + 1, board, ans, n);
//                 board[row][col] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n, '.');
//         for(int i=0; i<n; i++) board[i] = s;
//         solve(0, board, ans, n);
//         return ans;
//     }
// };

// Approach 2
// class Solution {
// public:
//     void solve2(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, svector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n){
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row=0; row<n; row++){
//             if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
//                 board[row][col] = 'Q';
//                 leftRow[row] = 1;
//                 lowerDiagonal[row + col] = 1;
//                 upperDiagonal[n - 1 + col - row] = 1;
//                 solve2(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
//                 board[row][col] = '.';
//                 leftRow[row] = 0;
//                 lowerDiagonal[row + col] = 0;
//                 upperDiagonal[n - 1 + col - row] = 0;
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n, '.');
//         for(int i=0; i<n; i++) board[i] = s;
//         vector<int> leftRow(n, 0);
//         vector<int> upperDiagonal(2 * n - 1, 0);
//         vector<int> lowerDiagonal(2 * n - 1, 0);
//         solve2(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
//         return ans;
//     }
// };


// Approach 3
class Solution {
public:
    bool isValid(vector<string>& board, int row, int col, int n){
        // Look Upward
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }
        // Look Upper Left Diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        // Look Upper Right Diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve3(vector<string>& board, int row, int n, vector<vector<string>>& result){
        if(row >= n){
            result.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){
            if(isValid(board, row, col, n)){
                board[row][col] = 'Q';
                solve3(board, row + 1, n, result);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        solve3(board, 0, n, result);
        return result;
    }
};

// Approach 4
// Upward: Use column array to check is a Queen is in a particular column
// Diagonal: (i + j) is a constant, and use diagonal array
// AntiDiagonal: (i - j) is a constant, and use antiDiagonal array
// class Solution {
// public:
//     unordered_set<int> column;
//     unordered_set<int> diagonal;
//     unordered_set<int> antiDiagonal;
//     void solve4(vector<string>& board, int row, int n, vector<vector<string>>& result){
//         if(row >= n){
//             result.push_back(board);
//             return;
//         }
//         for(int col=0; col<n; col++){
//             int diaConst = row + col;
//             int antiDiaConst = row - col;
//             if(column.find(col) != column.end() || diagonal.find(diaConst) != diagonal.end() 
//                 || antiDiagonal.find(antiDiaConst) != antiDiagonal.end()) continue;
//             // Insert if there is Queen
//             column.insert(col);
//             diagonal.insert(diaConst);
//             antiDiagonal.insert(antiDiaConst);
//             board[row][col] = 'Q';
//             solve4(board, row + 1, n, result);
//             // Remove Queen if not valid
//             column.erase(col);
//             diagonal.erase(diaConst);
//             antiDiagonal.erase(antiDiaConst);
//             board[row][col] = '.';
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n, string(n, '.'));
//         vector<vector<string>> result;
//         solve4(board, 0, n, result);
//         return result;
//     }
// };