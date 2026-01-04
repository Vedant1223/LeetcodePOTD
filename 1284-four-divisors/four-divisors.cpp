class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            int a = -1, b = -1;

            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    if (a != -1) { // second divisor pair found
                        a = -1;
                        break;
                    }
                    a = i;
                    b = n / i;
                    if (a == b) { // perfect square
                        a = -1;
                        break;
                    }
                }
            }

            if (a != -1) {
                ans += 1 + a + b + n;
            }
        }

        return ans;
    }
};
