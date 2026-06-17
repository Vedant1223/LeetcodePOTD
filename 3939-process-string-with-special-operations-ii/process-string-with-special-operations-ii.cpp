class Solution {
public:
    char processStr(string s, long long k) {
        long long ansLen = 0;

        for (char i : s) {

            if (i == '*' && ansLen > 0) {
                ansLen--;
            } else if (i == '#') {
                ansLen += ansLen;
            } else if (i == '%') {
                // do nothing
            } else if (i <= 'z' && i >= 'a') {
                ansLen++;
            }
        }

        if (ansLen <= k) {
            return '.';
        }

        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '*') {
                ansLen++;
            } else if (s[i] == '#') {
                ansLen = ansLen / 2;
                if (k >= ansLen) {
                    k = k - ansLen;
                }
            } else if (s[i] == '%') {
                k = ansLen - k - 1;
            } else if (s[i] <= 'z' && s[i] >= 'a') {
                ansLen--;
            }
                if (ansLen == k) {
                    return s[i];
                }
        }

        return '.';
    }
};