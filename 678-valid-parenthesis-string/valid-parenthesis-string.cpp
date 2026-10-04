class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int idx, int open, string& s, int n) {
        if (idx == n) {
            if (open == 0) {
                return true;
            } else {
                return false;
            }
        }
        if (dp[idx][open] != -1) {
            return dp[idx][open];
        }

        bool isValid = false;
        if (s[idx] == '*') {
            isValid |= solve(idx + 1, open + 1, s, n);

            isValid |= solve(idx + 1, open, s, n);

            if (open > 0) {
                isValid |= solve(idx + 1, open - 1, s, n);
            }

        } else if (s[idx] == '(') {
            isValid |= solve(idx + 1, open + 1, s, n);
        } else {
            if (open > 0)
                isValid |= solve(idx + 1, open - 1, s, n);
        }

        return dp[idx][open] = isValid;
    }

    bool checkValidString(string s) {

        int n = s.length();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, s, n);
    }
};