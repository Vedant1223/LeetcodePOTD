class Solution {
public:
    int t[51][51];
    int solve( int i, int j, vector<int> &v){
        // base case
        if( j-i+1 < 3){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }
        int ans = INT_MAX;
        
        for(int k = i+1; k < j; k++){
            int wt = solve(i, k, v)+  v[i]*v[j]*v[k] + solve(k, j, v);

            ans = min(wt, ans);

            // ab m keh rha i se k tak ka polygon alag 
            // k+1 se j tak ka polygon alag
        }
        t[i][j] = ans;
        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n  = values.size();
        memset(t, -1, sizeof(t));
        return solve(0, n-1 ,values);
    }
};