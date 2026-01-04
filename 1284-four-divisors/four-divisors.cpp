class Solution {
public:
    vector<int> check(int n){
        vector<int> v;
        for(int i = 2; i*i <=n ; i++){
            if(n % i == 0){
                v.push_back(i);
                if(i != n/i){
                    v.push_back(n/i);
                }
            }
        }
        return v;
    }

    int sum(vector<int> v){
        int sum = 0;
        for( int i : v){
            sum+=i;
        }
        return sum;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n : nums){
            vector<int> v = check(n);
            if(v.size() ==2 ){
                ans += (1 + n);
                ans+= sum(v);
            }
        }    
        return ans;
    }
};