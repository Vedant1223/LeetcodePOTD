class Solution {
public:

    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        vector<ll> rowSum(row, 0);
        vector<ll> colSum(col,0);

        ll total = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        if(total&1){
            return false;
        }
        ll upper = 0;
        for(int i = 0; i < row; i++){
            upper += rowSum[i];
            if(upper == total - upper){
                return true;
            }
        }
        
         upper = 0;
        for(int i = 0; i < col; i++){
            upper += colSum[i];
            if(upper == total - upper){
                return true;
            }
        }

        return false;
    }
};