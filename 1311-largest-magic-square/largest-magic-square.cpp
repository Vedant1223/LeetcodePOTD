class Solution {
public:
    bool calc(int m, int n , int size,  vector<vector<int>>& g, vector<vector<int>>& row, vector<vector<int>>& col){
        
        int sum = row[m][n+size-1];
        cout<< sum<< " ";
        if(n>0){
            sum -= row[m][n-1];
        }

        int sumi = 0;
        
        for(int i = m; i < m+size; i++){
            sumi = row[i][n+size-1];
            if(n>0) sumi -= row[i][n-1];

            if(sumi != sum) return false;
            else sumi = 0;
        }

        for(int i = n; i < n+size; i++){
            sumi = col[m+size-1][i];
            if(m>0) sumi -= col[m-1][i];

            if(sumi != sum) return false;
            else sumi = 0;
        }

        for(int i = 0; i < size; i++){
            sumi +=g[m+i][n+i];
        }
        if(sumi != sum){
            return false;
        }else sumi = 0;


        int r = m + size - 1;
        for(int i = 0; i < size; i++){
            sumi += g[r - i][n + i];
        }

        if(sumi != sum){
            return false;
        }else sumi = 0;

        return true;

    }

    bool solve(int s, int len, int wid, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& g){
        for(int i = 0; i <= len - s; i++){
            for(int j = 0; j <= wid - s; j++){
                if(calc(i, j, s, g, col, row)) return true;
            }
        }
        return false;
    }
    
    void print(vector<vector<int>> &v){
        for(int i =0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                cout<< v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int len = grid.size();
        int wid = grid[0].size();
        int mini = min(len, wid);
        
        vector<vector<int>> colSum(len,vector<int>(wid,0));
        vector<vector<int>> rowSum(len,vector<int>(wid,0));
        
       
        for(int i = 0; i < len; i++){
            for(int j = 0; j < wid; j++){
                
                rowSum[i][j] = grid[i][j];

                if(i>0) rowSum[i][j] += rowSum[i-1][j];
            }
        }

        for(int j = 0; j < wid; j++){
            for(int i = 0; i < len; i++){
                
                colSum[i][j] = grid[i][j];

                if(j>0) colSum[i][j] +=colSum[i][j-1];
            }
        }

        // print(rowSum);
        // print(colSum);

        for(int i = mini; i >= 2; i--){
            if(solve(i, len, wid, rowSum, colSum, grid)){
                return i;
            }
        }
        return 1;
    }
};