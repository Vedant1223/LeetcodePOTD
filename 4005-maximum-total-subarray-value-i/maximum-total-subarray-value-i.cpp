class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        long long ans = 1LL* k * (maxi - mini);
        // long long ans = (long long)* k * (maxi - mini);
        return ans;
    }
};