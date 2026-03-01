class Solution {
public:
    int minPartitions(string n) {
       int maxi = -1;
       for(char c : n){
            int a = c -'0';
            maxi = max(maxi, a);
       } 
       return maxi;
    }
};