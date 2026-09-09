// Approach 1 : Using BFS
// O(V + E) time and O(V) space
// class Solution {
// private: 
//     bool colorComponentBFS(int start, vector<vector<int>>& graph, vector<int>& color){
//         queue<int> q;
//         q.push(start);
//         color[start] = 0;
//         while(!q.empty()){
//             int curr = q.front();
//             q.pop();
//             for(auto it : graph[curr]){
//                 if(color[it] == -1){
//                     color[it] = !color[curr];
//                     q.push(it);
//                 }
//                 else if(color[it] == color[curr]) return false;
//             }
//         }
//         return true;
//     }
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<int> color(V, -1);
//         for(int i=0; i<V; i++){
//             if(color[i] == -1){
//                 if(colorComponentBFS(i, graph, color) == false) return false;
//             }
//         }
//         return true;
//     }
// };

// Approach 2 : Using DFS
// O(V + E) time and O(V) space
class Solution {
private:
    bool colorComponentDFS(int start, int col, vector<vector<int>>& graph, vector<int>& color){
        color[start] = col;
        for(auto it : graph[start]){
            if(color[it] == -1){
                if(colorComponentDFS(it, !col, graph, color) == false) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(colorComponentDFS(i, 0, graph, color) == false) return false;
            }
        }
        return true;
    }
};