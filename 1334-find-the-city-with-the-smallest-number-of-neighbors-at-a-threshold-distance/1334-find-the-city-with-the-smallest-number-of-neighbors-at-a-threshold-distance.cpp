class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create Adjacency / Distance Matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int i=0; i<n; i++) dist[i][i] = 0;
        // Floyd Warshall Algorithm
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        // Get the city with the Smallest Number of Neighbors at a Threshold Distance
        int cityCount = n;
        int cityNum = -1;
        for(int city=0; city<n; city++){
            int counter = 0;
            for(int adjCity=0; adjCity<n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold) counter++;
            }
            if(counter <= cityCount){
                cityCount = counter;
                cityNum = city;
            }
        }
        return cityNum;
    }
};