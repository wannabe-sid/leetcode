class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<char, int> mpp; // map<character, frequency>
        while(right < n){
            mpp[s[right]]++;
            while(mpp[s[right]] > 2){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            int len = right - left + 1;
            maxLen = max(maxLen, len);
            right++;
        }
        return maxLen;
    }
};