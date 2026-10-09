class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open += 2;
            } else {
                if(open > 0){
                    if (s[i + 1] == ')') {
                        open -=2;
                        i++;
                    } else {
                        ans++;
                        open-=2;
                    }
                }else{
                    if(s[i+1] == ')'){
                        ans++;
                        i++;
                    }else{
                        ans+=2;
                    }
                }
            }
        }
        return ans + open;
    }
};