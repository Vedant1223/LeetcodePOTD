class Solution {
public:
    int solve(int ind,int col, vector<vector<int>>& t){
        // cout<<"abhi ye h "<< ind<<" : "<<col;
        if(ind >= t.size()){
        // cout<<"ye h b1"<<endl;
            return 0;
        }
        if(col == t[ind].size() || col < 0){
        // cout<<"ye h b2"<< t[ind].size()<<"   "<< col <<endl;
            return 0;
        }
        // cout<<"rec1"<<endl;
        int maxi = t[ind][col] + min(solve(ind +1 , col,t), solve(ind+1, col+1,t));
        // cout<<"rec1"<<endl;

        return maxi;
    }

    int solveTB(int ind, int col, vector<vector<int>>& t, vector<vector<int>>& tab){
        
        if(ind >= t.size()){
            return 0;
        }
        if(col == t[ind].size() || col < 0){
            return 0;
        }
        if(tab[ind][col] != INT_MAX){
            return tab[ind][col];
        }
        int maxi = t[ind][col] + min(solveTB(ind +1 , col,t, tab), solveTB(ind+1, col+1,t, tab));

        tab[ind][col] = maxi;
        return maxi;
    }

    int solveBO(vector<vector<int>>& t, vector<vector<int>>& tab){
        for(int idx = t.size()-2; idx >= 0; idx--){
            for(int col = t[idx].size()-1 ; col >= 0; col--){

                tab[idx][col] = t[idx][col] + min(tab[idx+1][col], tab[idx+1][col+1]);
            
            }
        }
        return tab[0][0];
    }
    
    int solveSO(vector<vector<int>>&t, vector<int> &curr, vector<int> &next){
        for(int idx = t.size()-2; idx >= 0; idx--){
            for(int col = t[idx].size()-1 ; col >= 0; col--){

                curr[col] = t[idx][col] + min(next[col], next[col+1]);
            
            }
            next = curr;
        }
        return next[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        
        vector<vector<int>>tabulation(row+1, vector<int>(col+1, INT_MAX));
    vector<int> next = triangle[row-1];  // last row
    vector<int> curr(col, 0);           // same size as next


        for(int i = 0 ; i < col; i++){

            tabulation[row-1][i] = triangle[row-1][i];
            next.push_back(triangle[row-1][i]);
        
        }

        return solveSO(triangle, curr, next);
    }
};