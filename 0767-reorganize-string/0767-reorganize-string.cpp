// Approach 1 : Using Heap
// O(nlogn) time and O() space
// If frequency of any character in the string is greater than (n+1)/2, then that string cannot be reorganized
// class Solution {
// public:
//     string reorganizeString(string s) {
//         int n = s.length();
//         vector<int> freq(26, 0);
//         for(char& ch : s){
//             freq[ch - 'a']++;
//             if(freq[ch - 'a'] > (n + 1) / 2){
//                 return "";
//             }
//         }
//         priority_queue<pair<int, char>> maxHeap; // pair<frequency, character>
//         for(int i=0; i<26; i++){
//             char ch = i + 'a';
//             if(freq[i] > 0){
//                 maxHeap.push({freq[i], ch});
//             }
//         }
//         string result = "";
//         while(maxHeap.size() >= 2){
//             auto p1 = maxHeap.top();
//             maxHeap.pop();
//             auto p2 = maxHeap.top();
//             maxHeap.pop();
//             result.push_back(p1.second);
//             p1.first--;
//             result.push_back(p2.second);
//             p2.first--;
//             if(p1.first > 0) maxHeap.push(p1);
//             if(p2.first > 0) maxHeap.push(p2);
//         }
//         if(!maxHeap.empty()) result.push_back(maxHeap.top().second);
//         return result;
//     }
// };

// Approach 2
// O(n) time and O(1) space
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int maxFreq = 0;
        char maxFreqChar;
        for(char& ch : s){
            freq[ch - 'a']++;
            if(freq[ch - 'a'] > maxFreq){
                maxFreq = freq[ch - 'a'];
                maxFreqChar = ch;
            }
            if(freq[ch - 'a'] > (n + 1) / 2){
                return "";
            }
        }
        string result = s;
        int i = 0;
        while(freq[maxFreqChar - 'a'] > 0){
            result[i] = maxFreqChar;
            i += 2;
            freq[maxFreqChar - 'a']--;
        }
        for(char ch='a'; ch<='z'; ch++){
            while(freq[ch - 'a'] > 0){
                if(i >= n) i = 1;
                result[i] = ch;
                i += 2;
                freq[ch - 'a']--;
            }
        }
        return result;
    }
};