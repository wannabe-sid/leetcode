// O(n) time and O(1) space
class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<int> lastSeen(26, -1);
        int count = 0;
        int startIdx = 0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(lastSeen[ch - 'a'] >= startIdx){
                count++;
                startIdx = i;
            }
            lastSeen[ch - 'a'] = i;
        }
        return count + 1;
    }
};