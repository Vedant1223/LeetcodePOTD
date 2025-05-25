class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0 ;
        string str;

        for(auto w : words){
            str = "";
            char a = w[0];
            char b = w[1];

            str+= b;
            str +=a;

            // cout<<str<<endl;
            if(mp[str] == 0){
                mp[w]++;
            }
            else{
                mp[str]--;
                ans += 4;
            }
        }
        for(char c = 'a'; c <= 'z'; c++){
            str= "";
            str+=c;
            str+=c;

            if(mp[str] == 1){
                ans +=2;
                break;
            }
        }
        return ans;
    }
};