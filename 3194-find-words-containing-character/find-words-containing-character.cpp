class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (any_of(words[i].begin(), words[i].end(), [x](char ch) {
                return ch == x;
            })) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};