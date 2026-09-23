class DisjointSet{
    vector<int> rank, size, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ultParentU = findParent(u);
        int ultParentV = findParent(v);
        if (ultParentU == ultParentV) return;
        if(size[ultParentU] < size[ultParentV]){
            parent[ultParentU] = ultParentV;
            size[ultParentV] += size[ultParentU];
        }
        else{
            parent[ultParentV] = ultParentU;
            size[ultParentU] += size[ultParentV];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp; // map<mail, node>;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }
        vector<string> mergedMail[n];
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};