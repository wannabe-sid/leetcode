struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit] != nullptr);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node -> containsKey(bit)){
                node -> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    }
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node -> containsKey(1 - bit)){
                maxNum = maxNum | (1 << i);
                node = node -> get(1 - bit);
            }
            else{
                node = node-> get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> offlineQueries;
        for(int i=0; i<q; i++){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}}); //{mi, {xi, i}}
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(q, 0);
        int idx = 0;
        for(int i=0; i<q; i++){
            int mi = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int qIdx = offlineQueries[i].second.second;
            while(idx < n && nums[idx] <= mi){
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx == 0) ans[qIdx] = -1;
            else ans[qIdx] = trie.getMax(xi);
        }
        return ans;
    }
};