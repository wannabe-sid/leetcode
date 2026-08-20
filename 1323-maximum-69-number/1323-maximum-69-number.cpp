// Approach 1
// O(d) time and O(d) space
// class Solution {
// public:
//     int maximum69Number (int num) {
//         string temp = to_string(num);
//         for(char& ch : temp){
//             if(ch == '6'){
//                 ch = '9';
//                 break;
//             }
//         }
//         num = stoi(temp);
//         return num;
//     }
// };

// Approach 2
// O(d) time and O(d) space
class Solution {
public:
    int maximum69Number (int num) {
        int placeValue = 0;
        int placeValueOfSix = -1;
        int temp = num;
        while(temp > 0){
            int rem = temp % 10;
            if(rem == 6){
                placeValueOfSix = placeValue;
            }
            temp = temp / 10;
            placeValue++;
        }
        if(placeValueOfSix == -1) return num;
        return num + 3 * pow(10, placeValueOfSix);
    }
};