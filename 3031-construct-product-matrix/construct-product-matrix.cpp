class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long  product = 1;
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> v (row, vector<int>(col, 1));
        for(int i = row-1; i >=0; i--){
            for(int j = col-1; j >= 0; j--){
                v[i][j] = product;
                product = (product * grid[i][j]) % 12345;
            }
        }
        
        long long prefix = 1;
        for(int i = 0; i< row; i++){
            for(int j = 0; j < col; j++){
                v[i][j] = (prefix * v[i][j]) % 12345;
                prefix = (prefix * grid[i][j]) % 12345;
            }
        }
        return v;

    }
};