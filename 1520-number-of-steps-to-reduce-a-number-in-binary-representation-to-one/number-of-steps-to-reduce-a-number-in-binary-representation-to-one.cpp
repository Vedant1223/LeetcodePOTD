class Solution {
public:
    string makeStr(int len){
        string s = "1";
        for(int i = 0; i < len; i++){
            s+='0';
        }
        return s;
    }
    int numSteps(string s) {
        int ans = 0;
        while(s != "1"){
            int len = s.length();
            if(s[len-1] == '1'){
                for(int i = len-2; i >= 0; i--){
                    if(s[i] == '0'){
                        s[i] = '1';
                        s[len-1] = '0';
                        break;
                    }
                    else{
                        s[i] = '0';
                    }
                }
                if(s[len-1] == '1'){
                    // case of 111 to 1000
                    s = makeStr(len);
                }
            }else{
                s.pop_back();
            }
            ans++;
        }
        return ans;
    }
};