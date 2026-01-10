class Solution {
public:
    int solve(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp){

        if(ind1 == s1.size()){
            int sum  = 0;
            for(int p = ind2; p <s2.size(); p++){
                sum += (int)s2[p];
            }
            return sum;
        }

        if(ind2 == s2.size()){
            int sum = 0;
            for(int i = ind1; i < s1.size(); i++){
                sum += (int)s1[i];
            }
            return sum;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if( s1[ind1] == s2[ind2]){
            dp[ind1][ind2] = solve(s1,s2, ind1 + 1, ind2 + 1, dp);
            return dp[ind1][ind2];
        }
        else{
            int op1 = (int)s1[ind1] + solve(s1,s2, ind1 + 1, ind2, dp);
            int op2 = (int)s2[ind2] + solve(s1,s2, ind1, ind2 + 1, dp);
            dp[ind1][ind2] = min(op1, op2);
            return dp[ind1][ind2];
        }
    }

int solveBO(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: s1 exhausted
    for (int j = m - 1; j >= 0; j--) {
        dp[n][j] = dp[n][j + 1] + s2[j];
    }

    // Base case: s2 exhausted
    for (int i = n - 1; i >= 0; i--) {
        dp[i][m] = dp[i + 1][m] + s1[i];
    }

    // Fill the table bottom-up
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                dp[i][j] = min(
                    s1[i] + dp[i + 1][j],
                    s2[j] + dp[i][j + 1]
                );
            }
        }
    }

    return dp[0][0];
}


    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        // return solve(s1,s2, 0, 0, dp);
        return solveBO(s1,s2);
    }
};