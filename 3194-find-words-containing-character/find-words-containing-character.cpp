class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        std::vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (std::any_of(words[i].begin(), words[i].end(), [x](char ch) {
                return ch == x;
            })) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};