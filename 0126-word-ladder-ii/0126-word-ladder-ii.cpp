// N = number of words in wordList
// L = length of each word
// P = number of valid paths/sequences explored.
// O(P * (L^2 * 26 + L)) time and O(P * N * L) space
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         queue<vector<string>> q;
//         q.push({beginWord});
//         vector<string> usedOnLevel;
//         usedOnLevel.push_back(beginWord);
//         int level = 0;
//         vector<vector<string>> ans;
//         while(!q.empty()){
//             vector<string> vec = q.front();
//             q.pop();
//             if(vec.size() > level){
//                 level++;
//                 for(auto it : usedOnLevel) st.erase(it);
//             }
//             string word = vec.back();
//             if(word == endWord){
//                 if(ans.size() == 0) ans.push_back(vec);
//                 else if(ans[0].size() == vec.size()) ans.push_back(vec);
//             }
//             for(int i=0; i<word.size(); i++){
//                 char original = word[i];
//                 for(char ch='a'; ch<='z'; ch++){
//                     word[i] = ch;
//                     if(st.find(word) != st.end()){
//                         vec.push_back(word);
//                         q.push(vec);
//                         usedOnLevel.push_back(word);
//                         vec.pop_back();
//                     }
//                 }
//                 word[i] = original;
//             }
//         }
//         return ans;
//     }
// };

// Step1: Follow word ladder 1 and find the minimum steps and store the steps for each string in map
// Step2: Backtrack in map from end to start to get the answer
// Let N be the number of words in wordList and L be the length of each word.
// Let P be the number of valid shortest transformation paths found from endWord back to beginWord
// O(N * L * 26 + P * L^2 * 26) time and O(NL + PKL) space
// class Solution {
//     unordered_map<string, int> mpp;
//     vector<vector<string>> ans;
// private:
//     void dfs(string word, string beginWord, vector<string>& seq){
//         if(word == beginWord){
//             reverse(seq.begin(), seq.end());
//             ans.push_back(seq);
//             reverse(seq.begin(), seq.end());
//             return;
//         }
//         int steps = mpp[word];
//         int size = word.size();
//         for(int i=0; i<size; i++){
//             char original = word[i];
//             for(char ch='a'; ch<='z'; ch++){
//                 word[i] = ch;
//                 if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
//                     seq.push_back(word);
//                     dfs(word, beginWord, seq);
//                     seq.pop_back();
//                 }
//             }
//             word[i] = original;
//         }
//     }
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         queue<string> q;
//         q.push(beginWord);
//         mpp[beginWord] = 1;
//         st.erase(beginWord);
//         int size = beginWord.size();
//         while(!q.empty()){
//             string word = q.front();
//             int steps = mpp[word];
//             q.pop();
//             if(word == endWord) break;
//             for(int i=0; i<size; i++){
//                 char original = word[i];
//                 for(char ch='a'; ch<='z'; ch++){
//                     word[i] = ch;
//                     if(st.find(word) != st.end()){
//                         q.push(word);
//                         st.erase(word);
//                         mpp[word] = steps + 1;
//                     }
//                 }
//                 word[i] = original;
//             }
//         }
//         if(mpp.find(endWord) != mpp.end()){
//             vector<string> seq;
//             seq.push_back(endWord);
//             dfs(endWord, beginWord, seq);
//         }
//         return ans;
//     }
// };

class Solution {
private:
    void backtrack(string word, 
                   const string& beginWord, 
                   unordered_map<string, int>& levels, 
                   vector<string>& vec, 
                   vector<vector<string>>& ans) {
        if (word == beginWord) {
            vector<string> path = vec;
            reverse(path.begin(), path.end());
            ans.push_back(path);
            return;
        }

        int currLevel = levels[word];
        for (int i = 0; i < (int)word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original) continue;
                word[i] = ch;

                if (levels.find(word) != levels.end() && levels[word] == currLevel - 1) {
                    vec.push_back(word);
                    backtrack(word, beginWord, levels, vec, ans);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return {};

        // Track the level (shortest distance) at which each word is reached
        unordered_map<string, int> levels;
        levels[beginWord] = 0;

        // Push only strings into the queue rather than entire vectors
        queue<string> q;
        q.push(beginWord);

        bool reachedEnd = false;

        // Phase 1: BFS to find minimum steps/levels
        while (!q.empty()) {
            int sz = q.size();

            for (int k = 0; k < sz; k++) {
                string word = q.front();
                q.pop();

                int currLevel = levels[word];

                for (int i = 0; i < (int)word.size(); i++) {
                    char original = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (st.find(word) != st.end()) {
                            if (levels.find(word) == levels.end()) {
                                levels[word] = currLevel + 1;
                                q.push(word);
                            }
                            if (word == endWord) reachedEnd = true;
                        }
                    }
                    word[i] = original;
                }
            }
            if (reachedEnd) break;
        }

        if (levels.find(endWord) == levels.end()) return {};

        // Phase 2: Backtrack from endWord to beginWord
        vector<vector<string>> ans;
        vector<string> vec = {endWord};
        backtrack(endWord, beginWord, levels, vec, ans);

        return ans;
    }
};