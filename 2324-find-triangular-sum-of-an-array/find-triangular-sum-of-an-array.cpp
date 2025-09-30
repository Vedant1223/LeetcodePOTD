class Solution {
public:
    int solve(vector<int> v){
        if(v.size() == 1){
            return v[0];
        }
        
        vector<int> x(v.size()-1);
        for(int i = 0; i < v.size()-1; i++){
            x[i] = ( v[i] + v[i+1] ) % 10;
        }
        return solve(x);
    }

    int triangularSum(vector<int>& nums) {

        return solve(nums);
    }
};