// O(n) time and O(1) space
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(); 
        int leftQuestionMarks = 0;
        int leftSum = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                leftQuestionMarks++;
            } else {
                leftSum += num[i] - '0';
            }
        }
        int rightQuestionMarks = 0;
        int rightSum = 0;
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                rightQuestionMarks++;
            } else {
                rightSum += num[i] - '0';
            }
        }
        // Alice wins if:
        // 1. Total question marks is odd (Alice gets the last move)
        // 2. The difference in sums doesn't match the expected balance from question marks
        //    - Each pair of moves (Alice + Bob) can change the difference by at most 9
        //    - Bob needs exactly (rightQuestionMarks - leftQuestionMarks) / 2 pairs to balance
        //    - Each pair Bob uses optimally adds 9 to the side with fewer question marks
        int totalQuestionMarks = leftQuestionMarks + rightQuestionMarks;
        if(totalQuestionMarks % 2 == 1) return true;
        int left = 2 * leftSum + 9 * leftQuestionMarks;
        int right = 2 * rightSum + 9 * rightQuestionMarks;
        if(left == right) return false;
        return true;
    }
};