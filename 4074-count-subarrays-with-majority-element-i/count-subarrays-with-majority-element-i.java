class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
      int n = nums.length;
      int cur = 0 ;
      int ans = 0;
      for(int i =0 ; i < n;i++){
        cur = 0;
        for(int j = i ; j < n ; j++){
            if(nums[j] == target ){
                cur++;
            }
            int len =j - i + 1;
            int half = len / 2;
            if(cur > half) ans++;

        }
      }   
      return ans;
    }
}