class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        

        vector<int> ans;
        for(int n : nums){

            if(n == 2){
                ans.push_back(-1);
                continue;
            }

            for(int i = 1; i < 32; i++){
                if( n & (1 << i) ){
                    // that bit is set i.e. 1
                    continue;
                }

                int ne = n & ~(1 << (i-1));
                ans.push_back(ne);
                break;
            }
        }


        return ans;
    }
};