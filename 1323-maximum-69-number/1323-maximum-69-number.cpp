// Approach 1
// O(d) time and O(d) space
class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);
        for(char& ch : temp){
            if(ch == '6'){
                ch = '9';
                break;
            }
        }
        num = stoi(temp);
        return num;
    }
};