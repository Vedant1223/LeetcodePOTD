class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxi = INT_MIN;

        for(auto i : nums){
            if(mini > i) 
                mini = i;

            maxi = max( maxi, i - mini);
        }
        if(maxi > 0){
            return maxi;
        }
        else{
            return -1;
        }
    }
};