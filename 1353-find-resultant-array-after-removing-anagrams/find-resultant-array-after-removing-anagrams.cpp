
class Solution {
public:
    string countingSort(string str) {
        int freq[26] = {0};
        for (char c : str)
            freq[c - 'a']++;

        string ans;
        for (int i = 0; i < 26; i++)
            ans.append(freq[i], 'a' + i);
        return ans;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        if (words.empty()) return result;

        result.push_back(words[0]);
        string prevSorted = countingSort(words[0]);

        for (int i = 1; i < words.size(); i++) {
            string currSorted = countingSort(words[i]);
            if (currSorted != prevSorted) {
                result.push_back(words[i]);
                prevSorted = currSorted;
            }
        }
        return result;
    }
};