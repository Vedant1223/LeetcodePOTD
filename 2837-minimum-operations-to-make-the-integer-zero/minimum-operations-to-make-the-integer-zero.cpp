class Solution {
public:
    int makeTheIntegerZero(long long n1, long long n2) {
        for (int i = 1; i <= 60; i++) {
            
            long long a = n1 - i * n2;
            
            if (a < i) continue;  

            int minBits = __builtin_popcountll(a);

            if (minBits <= i && a >= i) {
            
                return i;
            
            }
        }
        return -1;
    }
};
