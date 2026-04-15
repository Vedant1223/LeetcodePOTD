class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        vector<int> targetInd;

        for(int i = 0; i < n; i++){
            if(words[i] == target){
                targetInd.push_back(i);
            }
        }

        
        if(targetInd.size() != 0){
            for(auto t : targetInd){

            int dif = abs(startIndex - t);
            dif = min(dif, n-dif);
            ans = min(dif, ans);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};