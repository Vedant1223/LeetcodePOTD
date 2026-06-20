class Solution {
public:
    void processRest(vector<vector<int>>& rest) {
        int len = rest.size();

        // left to right
        for (int i = 1; i < len; i++) {
            int dist = rest[i][0] - rest[i - 1][0];
            int best = rest[i - 1][1] + dist;

            rest[i][1] = min(rest[i][1], best);
        }

        // right to left
        for (int i = len - 2; i >= 0; i--) {
            int dist = rest[i + 1][0] - rest[i][0];
            int best = rest[i + 1][1] + dist;

            rest[i][1] = min(rest[i][1], best);
        }
    }

    int findAns(int n, vector<vector<int>>& rest) {
        int len = rest.size();
        int maxi = 0;
        for (int i = 0; i < len-1; i++) {
            int dist = rest[i+1][0]  - rest[i][0];
            maxi = max(maxi, max(rest[i][1], rest[i+1][1]) + (dist - abs(rest[i][1] - rest[i+1][1]))/2);  
        }
        return maxi;
    }

    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1, 0});
        rest.push_back({n, n-1});
        sort(rest.begin(), rest.end());

        // first process the individual rest
        processRest(rest);

        int ans = findAns(n, rest);
        return ans;
    }
};