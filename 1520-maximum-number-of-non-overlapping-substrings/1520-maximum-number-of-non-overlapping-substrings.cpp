// Kosaraju's Algorithm
// Strongly connected components are only valid for directed graphs
// Maximum non-overlapping substrings = All sink components (out-degree = 0)
// 1. Sort all the edges according to decreasing finishing times
// 2. Reverse the graph
// 3. Do a DFS traversal
// O(n) time and O(n) space
class Solution {
public:
    // DFS 1: Order letters by finishing time
    void dfs1(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) dfs1(v, adj, vis, st);
        }
        st.push(u);
    }
    // DFS 2: Traverse on reversed graph to extract each SCC
    void dfs2(int u, vector<vector<int>>& revAdj, vector<bool>& vis, vector<int>& comp) {
        vis[u] = true;
        comp.push_back(u);
        for (int v : revAdj[u]) {
            if (!vis[v]) dfs2(v, revAdj, vis, comp);
        }
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        // 1. Find the first and last position of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        // 2. Build graph: u -> v means character u contains character v inside its range
        vector<vector<int>> adj(26), revAdj(26);
        for (int u = 0; u < 26; u++) {
            if (first[u] == -1) continue;
            for (int i = first[u]; i <= last[u]; i++) {
                int v = s[i] - 'a';
                if (u != v) {
                    adj[u].push_back(v);
                    revAdj[v].push_back(u);
                }
            }
        }
        // 3. Kosaraju: Pass 1
        stack<int> st;
        vector<bool> vis(26, false);
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && !vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }
        // 4. Kosaraju: Pass 2 (collect SCCs)
        fill(vis.begin(), vis.end(), false);
        vector<vector<int>> sccs;
        vector<int> compId(26, -1);
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!vis[u]) {
                vector<int> comp;
                dfs2(u, revAdj, vis, comp);
                for (int node : comp) compId[node] = sccs.size();
                sccs.push_back(comp);
            }
        }
        // 5. Find outgoing edges for each SCC
        int totalSCCs = sccs.size();
        vector<int> outDegree(totalSCCs, 0);
        for (int u = 0; u < 26; u++) {
            if (first[u] == -1) continue;
            for (int v : adj[u]) {
                if (compId[u] != compId[v]) {
                    outDegree[compId[u]]++; // Component points to another component
                }
            }
        }
        // 6. Every sink component (outDegree == 0) is a valid substring
        vector<string> result;
        for (int i = 0; i < totalSCCs; i++) {
            if (outDegree[i] == 0) {
                int left = n, right = -1;
                for (int c : sccs[i]) {
                    left = min(left, first[c]);
                    right = max(right, last[c]);
                }
                result.push_back(s.substr(left, right - left + 1));
            }
        }
        return result;
    }
};