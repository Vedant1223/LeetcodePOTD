class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        long long ans = 0;
        long long validLeftPoints = 0;
        int cSum = 0;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == target){
                validLeftPoints += mp[cSum];
                cSum++;
            }else{
                cSum--;
                validLeftPoints -= mp[cSum];
            }
            mp[cSum]++;
            ans += validLeftPoints;
        }
        return ans; 

    }
};