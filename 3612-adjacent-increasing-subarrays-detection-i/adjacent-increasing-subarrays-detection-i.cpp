class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;
        int maxResult = 0;

        for( int i = 0; i < n-1; i++ ){
            if(nums[i+1] > nums[i]){
                currRun++;
            }else{
                prevRun = currRun;
                currRun = 1;
            }
            if(currRun == 2*k){
                return true;
            }
            if(min(currRun, prevRun) == k){
                return true;
            }
        }

        return false;
    }
};