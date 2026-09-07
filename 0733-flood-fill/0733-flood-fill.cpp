// O(n*m) time and O(n*m) space
class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int iniColor, int newColor){
        if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != iniColor) return;
        image[r][c] = newColor;
        dfs(image, r + 1, c, iniColor, newColor);
        dfs(image, r - 1, c, iniColor, newColor);
        dfs(image, r, c + 1, iniColor, newColor);
        dfs(image, r, c - 1, iniColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        if(iniColor != newColor) dfs(image, sr, sc, iniColor, newColor);
        return image;
    }
};