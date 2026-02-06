class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j =1;
        int maxi = INT_MIN;
        int n = nums.size();
        if(n==1) return 0;

        while( nums.size() > j){
            long long num = 1LL * nums[i]*k;

            if(num >= nums[j]){
                j++;
            }
            else{
                i++;
            }
            maxi = max(maxi, j-i);
        }

        return n-maxi;
    }
};