class Solution {
public:
    bool check(char ch){
        if(ch == 'a' || ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        
        for(auto c: s){
            if(check(c)){
               return true;
            }
        }
        return false;
    }
};