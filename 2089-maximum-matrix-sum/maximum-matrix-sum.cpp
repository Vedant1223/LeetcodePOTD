class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int count = 0;
        long long sum = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j]<0){
                    count++;
                }
                int a = abs(matrix[i][j]);
                mini = min(mini,a);
                sum += a;
            }
        }

        if(count & 1){
            sum -= (2*mini);
        }
        return sum;
    }
};