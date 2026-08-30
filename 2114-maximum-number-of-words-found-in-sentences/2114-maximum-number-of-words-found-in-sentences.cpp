class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        for (string& sentence : sentences) {
            int spaces = count(sentence.begin(), sentence.end(), ' ');
            maxWords = max(maxWords, spaces + 1);
        }
        return maxWords;
    }
};