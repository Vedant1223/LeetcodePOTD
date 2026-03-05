class Solution {
public:
    int minOperations(string s) {
        int p1 = 0; // 0 1 0 1 
        int p2 = 0; // 1 0 1 0 
        for(int i = 0; i < s.length(); i++){
            if(i&1){
                // odd 
                if(s[i] == '0'){
                    p1++;
                }else{
                    p2++;
                }
            }else{
                if(s[i]=='0'){
                    p2++;
                }else{
                    p1++;
                }
            }
        }

        return min(p1, p2);
    }
};