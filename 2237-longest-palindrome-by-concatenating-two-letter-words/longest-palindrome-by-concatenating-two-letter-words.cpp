class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0 ;
        string str;

        for (const string& w : words) {
            string rev = {w[1], w[0]};

            if (mp[rev] > 0) {
                mp[rev]--;
                ans += 4;
            } else {
                mp[w]++;
            }
        }

        for(char c = 'a'; c <= 'z'; c++){
            str = {c, c};

            if(mp[str] == 1){
                ans +=2;
                break;
            }
        }
        return ans;
    }
};