class Solution {
public:
    int numSteps(string s) {
        int len = s.length();
        int carry = 0;
        int ans = 0;
        for(int i = len-1; i >= 1; i--){
            if(s[i] == '1' && carry == 1){
                // even 
                ans += 1;
                carry = 1;
            }
            else if( s[i] == '1' && carry == 0){
                // add one thats the odd case
                ans +=2;
                carry = 1;
            }
            else if(s[i] == '0' && carry == 1){
                ans +=2;
                carry = 1;
            }
            else{
                ans+=1;
            }
        }
        if(carry == 1){
            ans ++;
        }   
        return ans;
    }
};