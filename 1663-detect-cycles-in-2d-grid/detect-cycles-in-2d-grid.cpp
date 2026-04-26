class Solution {
public:
    int m;
    int n;

    vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, -1}, {0, 1}}; 

    bool cycleDetect(int r , int c , int prev_i, int prev_j, vector<vector<bool>> &vis, vector<vector<char>> &grid){

        if( vis[r][c]){
            return true;
        }
        // explore 
        vis[r][c] = true;

        for(auto &d : dir){
            int new_r = r+d[0];
            int new_c = c+d[1];

            if( new_r >= 0 && new_r < m && new_c >=0 && new_c <n && grid[r][c] == grid[new_r][new_c] ){
                if(new_r == prev_i && new_c == prev_j){
                    continue;
                }
                if(cycleDetect(new_r, new_c, r, c, vis, grid)){
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> vis(m , vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( !vis[i][j] && cycleDetect(i, j, i, j, vis, grid)){
                    return true;
                }
            }
        }
        return false;
    }
};