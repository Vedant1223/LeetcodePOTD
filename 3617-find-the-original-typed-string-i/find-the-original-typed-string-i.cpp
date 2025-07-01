class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> v;
        int count = 1;
        for(int i = 1; i < word.length(); i++){
            if(word[i] == word[i-1]){
                count++;
            }
            else{
                // if(count != 1){
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);


        int res = 1;
        for(auto i : v){
            if(i != 1){
                res += (i-1);
            }
        }
        return res;

    }
};