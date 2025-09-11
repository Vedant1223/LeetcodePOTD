// counting sort 

class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O'|| ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u'){
            return true;
        }
        return false;
    }

    string sortVowels(string s) {
        // step 1 count then first 
        unordered_map<char, int> mp;
        // char is key which are the vowels and then int is the occurence

        string str = "AEIOUaeiou";
        // this is the ordered vowels as per asciii

        for(char c : s){
            if(isVowel(c)){
                mp[c]++;
            }
        }// now i have the count 
        int j = 0;

        for(int i = 0 ; i < s.length(); i++){

            if(isVowel(s[i])){
                while (mp[str[j]] == 0) {
                    j++;
                }
                s[i] = str[j];
                mp[str[j]]--;
            }
        }
        return s;
    }
};



// this is O(nlogn solution)


// class Solution {
// public:
//     bool isVowel(char ch){
//         if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O'|| ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u'){
//             return true;
//         }
//         return false;
//     }
//     string sortVowels(string s) {
//         string temp;
//         for( char ch : s){
//             if(isVowel(ch)){
//                 temp.push_back(ch);
//             }
//         }

//         sort(temp.begin(), temp.end());
//         int j = 0;

//         for(int i = 0; i < s.length(); i++){
//             if(isVowel(s[i])){
//                 s[i] = temp[j];
//                 j++;
//             }
//         }
    
//         return s;
//     }

// };