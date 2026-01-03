static const int MOD = 1e9 + 7;

class Solution {
public:

    int numOfWays(int n) {
       long long  samePrev = 6;
       long long diffPrev = 6;
       long long newSame, newDiff;

        vector<long long> same;
        same.push_back(6);

        vector<long long> diff;
        diff.push_back(6);

        for(int i = 1; i <n; i++){
            newSame = (3*same[i-1]) % MOD + (2*diff[i-1])% MOD;
            newDiff = (2*same[i-1]) % MOD+ (2*diff[i-1]) % MOD;

            same.push_back(newSame);
            diff.push_back(newDiff);
        }

        return (same.back() + diff.back()) % MOD;
    }
};