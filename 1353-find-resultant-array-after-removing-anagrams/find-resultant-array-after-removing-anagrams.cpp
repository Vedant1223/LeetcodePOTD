class Solution {
public:

    string countingSort( string str){
        int freq[26] = {0};
        for(char i : str){
            int idx = i - 'a';
            freq[idx]++;
        }
        string ans;

        for(int i = 0 ; i < 26; i++){
            ans.append(freq[i], 'a' + i);
        }
        return ans;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);
        string prevSort = countingSort(words[0]);

        for( int i = 1; i < words.size(); i++){

            string currSort = countingSort(words[i]);
            
            if(currSort != prevSort){
                result.push_back(words[i]);
                prevSort = currSort;
            }
        }
        return result;
    }
};