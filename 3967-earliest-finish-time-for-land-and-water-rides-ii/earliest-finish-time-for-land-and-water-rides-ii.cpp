class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int miniFirst = INT_MAX;
        for(int i = 0; i < landDuration.size(); i++){
            miniFirst = min(miniFirst, landStartTime[i] + landDuration[i]);
        }
        int ans = INT_MAX;

        int miniSec = INT_MAX;
        for( int i  = 0; i < waterDuration.size();i++){
            miniSec = min(miniSec, waterStartTime[i]+ waterDuration[i]);
           
                ans = min(ans,  max(waterStartTime[i], miniFirst) + waterDuration[i] );
            
        }    
        for( int i = 0; i < landDuration.size(); i++){
            
                ans = min(ans, max(landStartTime[i], miniSec) + landDuration[i]);

        }

        return ans;
    }
};