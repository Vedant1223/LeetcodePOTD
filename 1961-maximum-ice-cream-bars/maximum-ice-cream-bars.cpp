class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int i = 0;
        while(i < costs.size() && costs[i] <= coins ){
            coins -= costs[i];
            i++;
        }

        return i;
    }
};