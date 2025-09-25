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

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        
        vector<vector<int>>tabulation(row, vector<int>(col, INT_MAX));


        return solveTB(0, 0, triangle, tabulation);
    }
};