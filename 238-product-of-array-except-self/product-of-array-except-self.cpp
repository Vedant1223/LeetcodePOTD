class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n,0);
        int f = 1;

        for(int i = 0 ; i < nums.size(); i++){
            left[i] = f;
            f *= nums[i];
        }
        f = 1;
        for(int i = n-1; i >= 0; i--){
            right[i] = f;
            f *= nums[i];
        }

        vector<int> ans(n, 1);
        for( int i = 0 ; i < n; i++){
            ans[i] = left[i]* right[i];
        }

        return ans;
    }
};