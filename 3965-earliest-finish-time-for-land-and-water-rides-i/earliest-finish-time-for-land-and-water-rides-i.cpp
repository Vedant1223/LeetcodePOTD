class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = waterDuration.size();
        int m = landDuration.size();
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            int landFin = landStartTime[i] + landDuration[i];
            for (int j = 0; j < n; j++) {
                ans = min(ans, max(landFin, waterStartTime[j]) + waterDuration[j]);
            }
        }

        for(int j = 0; j < n; j++){
             int waterFin = waterStartTime[j] + waterDuration[j];
            for(int i = 0; i < m; i++){
                ans = min(ans , max(waterFin, landStartTime[i]) + landDuration[i]);
            }
        }

        return ans;
    }
};