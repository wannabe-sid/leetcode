// O(n + m + nlogn + mlogn) time and O(1) space
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;  // for children (g)
        int right = 0; // for cookies (s)
        while(left < g.size() && right < s.size()){
            if(s[right] >= g[left]) left++;
            right++;
        }
        return left;
    }
};