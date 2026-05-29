class Solution {
public:
    int solve(int n){
        int ans = 0;
        while( n > 0){
            ans += n%10;
            n = n/10;
        }
        return ans;
    }

    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i : nums){
            cout<< "for"<< i <<" the sum "<< solve(i)<< endl;
            mini = min( mini, solve(i));
        }
        return mini;
    }
};