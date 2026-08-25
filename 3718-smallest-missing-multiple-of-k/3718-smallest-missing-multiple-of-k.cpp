class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int& num : nums) st.insert(num);
        for(int i=1; ; i++){
            int mult = k * i;
            if(!st.contains(mult)) return mult;
        }
    }
};