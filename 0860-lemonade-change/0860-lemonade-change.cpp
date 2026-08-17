// O(n) time and O(1) space
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0;
        int tens  = 0;
        for(int i=0; i<n; i++){
            if(bills[i] == 5) fives += 1;
            else if(bills[i] == 10){
                if(fives){
                    fives -= 1;
                    tens += 1;
                }
                else return false;
            }
            else{
                if(tens && fives){
                    tens -= 1;
                    fives -= 1;
                }
                else if(fives >= 3) fives -= 3;
                else return false;
            }
        }
        return true;
    }
};