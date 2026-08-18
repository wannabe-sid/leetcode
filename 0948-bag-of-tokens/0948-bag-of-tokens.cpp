class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = n - 1;
        int score = 0;
        int maxScore = 0;
        while(j >= i){
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
                maxScore = max(maxScore, score);
            }
            else if(score >= 1){
                power += tokens[j];
                score--;
                j--;
                maxScore = max(maxScore, score);
            }
            else return maxScore;
        }   
        return maxScore;
    }
};