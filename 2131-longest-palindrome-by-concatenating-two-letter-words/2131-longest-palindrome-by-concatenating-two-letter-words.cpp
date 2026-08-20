// O(words.size()) time and O(words.size()) space
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for(string& word : words){
            mpp[word]++;
        }
        bool centerUsed = false;
        int result = 0;
        for(string& word : words){
            string rev = word;
            reverse(rev.begin(), rev.end());
            if(rev != word){
                if(mpp[word] > 0 && mpp[rev] > 0){
                    mpp[word]--;
                    mpp[rev]--;
                    result += 4;
                }
            }
            else{
                if(mpp[word] >= 2){
                    mpp[word] -= 2;
                    result += 4;
                }
                else if(mpp[word] == 1 && centerUsed == false){
                    mpp[word]--;
                    result += 2;
                    centerUsed = true;
                }
            }
        }
        return result;
    }
};