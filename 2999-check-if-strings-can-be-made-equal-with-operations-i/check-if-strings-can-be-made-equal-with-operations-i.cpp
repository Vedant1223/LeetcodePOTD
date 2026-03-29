class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char, int> mpEven;
        unordered_map<char,int> mpOdd;

        for(int i = 0 ; i < s1.length(); i+=2){
            mpEven[s1[i]] = 1;
        }
        for(int i = 1 ; i < s1.length(); i+=2){
            mpOdd[s1[i]] = 1;
        }

        int odd = 0;
        int even = 0;
        for(int i = 0 ; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                if(i&1){
                    if(mpOdd.find(s2[i]) == mpOdd.end()){
                        return false;
                    } 
                    odd++;
                }
                else{
                    if(mpEven.find(s2[i])== mpEven.end()){
                        return false;
                    }
                    even++;
                }
            }
        }

        if( even & 1 || odd & 1){
            return false;
        }
        return true;
    }
};