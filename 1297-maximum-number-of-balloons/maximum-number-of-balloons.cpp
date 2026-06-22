class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v = { 0 , 0 , 0 , 0 , 0 };
        for(char c : text){
            if(c == 'b'){
                v[0]++;
            }else if(c == 'a'){
                v[1]++;
            }else if(c == 'l'){
                v[2]++;
            }else if(c == 'o'){
                v[3]++;
            }else if(c == 'n'){
                v[4]++;
            }
        }

        v[2] = v[2]/2;
        v[3] = v[3]/2;
        int ans = INT_MAX;
        for(int i = 0; i < v.size(); i++){
            ans = min(ans, v[i]);
        }
        return ans;
    }
};