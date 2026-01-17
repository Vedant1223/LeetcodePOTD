class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int xOverlap = min(topRight[i][0], topRight[j][0]) -
                               max(bottomLeft[i][0], bottomLeft[j][0]);

                int yOverlap = min(topRight[i][1], topRight[j][1]) -
                               max(bottomLeft[i][1], bottomLeft[j][1]);

                if (xOverlap > 0 && yOverlap > 0) {
                    long long side = min(xOverlap, yOverlap);
                    maxArea = max(maxArea, side * side);
                }
            }
        }

        return maxArea;
    }
};
