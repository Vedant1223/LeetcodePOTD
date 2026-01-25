class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        queue<int> q;
        int n = nums.size();
        
        for(int i =0; i < k;i++){
            q.push(nums[i]);
        }
        int l = q.back();
        int f = q.front();
        int mini = l-f;

        int i  = k;
        while( i < n){
            q.pop();
            q.push(nums[i]);

            l = q.back();
            f = q.front();
            int curr = l-f;
            mini = min(mini, curr);
            i++;
        }

        return mini;
    }
};