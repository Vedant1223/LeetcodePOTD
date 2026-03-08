class Solution {
public:
    string ans;
    void generate(int i, int n, string &curr, unordered_map<string,bool> &mp){
        
        if(i == n){
            if(mp.find(curr) == mp.end()){
                ans = curr;
            }
            return;
        }

        // choose 0
        curr.push_back('0');
        generate(i+1, n, curr, mp);
        curr.pop_back();

        // choose 1
        curr.push_back('1');
        generate(i+1, n, curr, mp);
        curr.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool> mp;
        for(auto s : nums){
            mp[s] = true;
        }

        int len = nums[0].length();
        string curr="";
        
        generate(0, len, curr, mp);
        return ans;
        // generator function for len 
    }
};