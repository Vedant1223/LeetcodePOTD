class Solution {
public:
    int solve(unordered_map<int, int> &mp, vector<int>& r, int idx) {
        for (int i = idx + 1; i < r.size(); i++) {
            if (r[i] != 0 && mp.find(r[i]) != mp.end()) {
                if(mp[r[i]] == 1){
                    mp[r[i]] = 0; // dry this lake
                    return r[i];
                }
            }
        }
        return 1;
    }

vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();

    unordered_map<int, int> lastRain;  // lake -> last day it was filled
    set<int> dryDays;                  
    vector<int> ans(n, 1);             // by default, dry day = 1 (any lake)
    
    for (int i = 0; i < n; i++) {
        int lake = rains[i];

        if (lake == 0) {
           
            dryDays.insert(i);
            continue;
        }

        ans[i] = -1; 

     
        if (lastRain.count(lake)) {
            int prevDay = lastRain[lake];

            
            auto it = dryDays.upper_bound(prevDay);

            if (it == dryDays.end()) {
                
                return {};
            }

          
            int dryDay = *it;
            ans[dryDay] = lake;  
            dryDays.erase(it);   
        }

        
        lastRain[lake] = i;
    }

    return ans;
}
};
