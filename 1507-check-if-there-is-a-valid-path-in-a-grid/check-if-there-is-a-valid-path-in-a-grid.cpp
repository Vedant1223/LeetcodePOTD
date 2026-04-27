class Solution {
public:
    int m;
    int n;

    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    vector<vector<pair<int, int>>> pathType = {
        {{0, 1}, {0, -1}}, {{-1, 0}, {1, 0}},  {{1, 0}, {0, -1}},
        {{1, 0}, {0, 1}},  {{0, -1}, {-1, 0}}, {{0, 1}, {-1, 0}}};

    bool isValid(int r, int c, int new_r, int new_c, vector<vector<int>>& grid,
                 vector<vector<bool>>& vis) {

        if (new_r < 0 || new_c < 0 || new_r >= m || new_c >= n) {
            return false;
        }
        if (vis[new_r][new_c]) {
            return false;
        }
        int newPath = grid[new_r][new_c];
        vector<pair<int, int>> next = pathType[newPath - 1];

        for (auto n : next) {
            int x = new_r + n.first;
            int y = new_c + n.second;

            if (x == r && y == c) {
                return true;
            }
        }
        return false;
    }

    bool dfs(int r, int c, vector<vector<bool>>& vis,
             vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1) {
            return true;
        }
        int val = grid[r][c];
        vector<pair<int, int>> pairs = pathType[val - 1];
        vis[r][c] = true;
        bool ans = false;
        for (auto p : pairs) {
            int new_r = r + p.first;
            int new_c = c + p.second;
            if (isValid(r, c, new_r, new_c, grid, vis)) {
                if (dfs(new_r, new_c, vis, grid))
                    ans = true;
            }
        }
        return ans;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        return dfs(0, 0, vis, grid);
    }
};