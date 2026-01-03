class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        unordered_map<int, int> mp;
        int i = 0;
        while(true){
            if(mp.find(nums[i]) != mp.end()){
                return nums[i];
            }
            else{
                mp[nums[i]] = 1;
            }
            i++;
        }
    }
};