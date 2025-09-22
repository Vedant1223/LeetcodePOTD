class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> m(101,0);
        int maxi = 0;
        for(int i = 0; i<  nums.size(); i++){
            m[nums[i]]++;
            if(maxi < m[nums[i]]){
                maxi = m[nums[i]];
            }
        }
        int count = 0;
        for(auto i: m){
            cout<<i<<endl;
            if(i== maxi){
                count++;
            }
        }
        return count*maxi;
    }
};