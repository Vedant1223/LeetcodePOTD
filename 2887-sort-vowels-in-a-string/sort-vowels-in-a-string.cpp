class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O'|| ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string temp;
        for( char ch : s){
            if(isVowel(ch)){
                temp.push_back(ch);
            }
        }

        sort(temp.begin(), temp.end());
        int j = 0;

        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }
    
        return s;
    }

};