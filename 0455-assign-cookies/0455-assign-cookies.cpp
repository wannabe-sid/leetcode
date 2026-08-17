class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;  // for children (g)
        int right = 0; // for cookies (s)
        int count = 0;
        while(left < g.size() && right < s.size()){
            if(s[right] >= g[left]){
                count++;
                left++;
                right++;
            }
            else if(s[right] < g[left]){
                right++;
            }
        }
        return count;
    }
};