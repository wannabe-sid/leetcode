// Approach 1 : Using Heap
// O() time and O() space
// If frequency of any character in the string is greater than (n+1)/2, then that string cannot be reorganized
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for(char& ch : s){
            freq[ch - 'a']++;
            if(freq[ch - 'a'] > (n + 1) / 2){
                return "";
            }
        }
        priority_queue<pair<int, char>> maxHeap; // pair<frequency, character>
        for(int i=0; i<26; i++){
            char ch = i + 'a';
            if(freq[i] > 0){
                maxHeap.push({freq[i], ch});
            }
        }
        string result = "";
        while(maxHeap.size() >= 2){
            auto p1 = maxHeap.top();
            maxHeap.pop();
            auto p2 = maxHeap.top();
            maxHeap.pop();
            result.push_back(p1.second);
            p1.first--;
            result.push_back(p2.second);
            p2.first--;
            if(p1.first > 0) maxHeap.push(p1);
            if(p2.first > 0) maxHeap.push(p2);
        }
        if(!maxHeap.empty()) result.push_back(maxHeap.top().second);
        return result;
    }
};

// Approach 2
// O() time and O() space
// class Solution {
// public:
//     string reorganizeString(string s) {
        
//     }
// };