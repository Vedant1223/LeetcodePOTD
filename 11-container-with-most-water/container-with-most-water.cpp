class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxi = INT_MIN;
        int curr;
        while(l<r){
                        
            curr = (r-l)*min(height[r], height[l]);
            maxi = max(curr, maxi);

            if(height[l]< height[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return maxi;
    }
};