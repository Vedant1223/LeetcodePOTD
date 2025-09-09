class Solution {
public:
    bool check( int n){
        if(n/10 == 0){
            if(n == 0){
                return false;
            }
            else{
                return true;
            }
        }

        int a = n/10;
        int b = n%10;
        if(b == 0){
            return false;
        }
        else{
            return check(a);
        }

    }

    vector<int> getNoZeroIntegers(int n) {
        for( int i = 1; i <= n/2; i++){
            if(check(i) && check(n-i)){
                return {i, n-i};
            }
        }
        return {};
    }
};