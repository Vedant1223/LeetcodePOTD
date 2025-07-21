class Solution {
public:
    string makeFancyString(string str) {
        int count   = 1;
        string s1 = "";
        s1.push_back(str[0]);
        for(int i = 1; i < str.length(); i++){
            if(str[i] == str[i-1]){
                count++;
                if(count == 3){
                    // ignore one time
                    count = 2;
                }
                else{
                    s1.push_back(str[i]);
                }
            
            }
            else{
                count = 1;
                s1.push_back(str[i]);
            }
        }
        return s1;
    }
};