class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        int maxi = 0;
        for (auto it : mp) {
            int num = it.first;
            if (mp.find(num + 1) != mp.end()) {
                maxi = max(maxi, mp[num] + mp[num + 1]);
            }
        }
        return maxi;
    }
};
