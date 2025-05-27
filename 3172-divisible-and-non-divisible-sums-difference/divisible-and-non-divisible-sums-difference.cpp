class Solution {
public:
    int differenceOfSums(int n, int m) {
        int i = n/m;

        int total = n*(n+1)/2;
        int iSum = m*(i*(i+1)/2);
        
        int ans = total - 2* iSum;
        
        return ans;
    }
};