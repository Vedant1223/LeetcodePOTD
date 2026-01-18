class Solution {
public:
    bool calc(int m, int n , int size, vector<vector<int>> &grid){
        int sum = 0;

        for(int i = m; i< m+size; i++){ 
            sum += grid[i][n];
        }

        int sumi = 0;
        
        for(int i = m; i < m+size; i++){
            for(int j = n; j < n+size; j++){
                sumi +=grid[i][j];
            }
            if(sumi != sum){
                return false;
            }else{
                sumi = 0;
            }
        }


        for(int j = n; j < n+size; j++){
            for(int i = m; i < m+size; i++){
                sumi+=grid[i][j];
            }

            if(sumi != sum){
                return false;
            }
            else{
                sumi = 0;
            }
        }

        

        for(int i = 0; i < size; i++){
            sumi +=grid[m+i][n+i];
        }
        if(sumi != sum){
            return false;
        }else sumi = 0;


        int r = m + size - 1;
        for(int i = 0; i < size; i++){
            sumi += grid[r - i][n + i];
        }

        if(sumi != sum){
            return false;
        }else sumi = 0;

        return true;
    }

    bool solve(int s, int len, int wid, vector<vector<int>>& g){
        for(int i = 0; i <= len - s; i++){
            for(int j = 0; j <= wid - s; j++){
                bool ok = calc(i, j, s, g);
                if(ok) return true;
            }
        }
        return false;
    }

    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int len = grid.size();
        int wid = grid[0].size();
        int mini = min(len, wid);
        
        for(int i = mini; i >= 2; i--){
            if(solve(i,len, wid, grid)){
                // cout<<i<<"  "<< len<<" "<< wid<<endl;
                return i;
            }
        }

        return 1;
    }
};