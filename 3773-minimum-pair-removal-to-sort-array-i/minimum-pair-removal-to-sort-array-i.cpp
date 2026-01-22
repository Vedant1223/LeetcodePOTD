class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        bool sort = is_sorted(nums.begin(), nums.end());    
        int op = 0;
        while(!sort){
            int mini = INT_MAX;
            int ind = 0;            
            for(int i = 0; i < nums.size()-1; i++){
                if(nums[i]+nums[i+1] < mini){
                    mini = nums[i]+nums[i+1];
                    ind = i;
                }
            }
            nums[ind] = nums[ind]+ nums[ind+1]; 
            nums.erase(nums.begin()+ind+1);
            
            sort = is_sorted(nums.begin(), nums.end());
            op++;
        }
        return op;
    }
};