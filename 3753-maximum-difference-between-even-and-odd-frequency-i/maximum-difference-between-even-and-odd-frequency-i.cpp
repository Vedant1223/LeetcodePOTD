class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26, 0);

        int oddMaxi = 0; 
        int evenMini = INT_MAX;

        int ind;
        for(auto c : s){
            ind = c -'a';
            v[ind]++;
        }

        for( auto i : v){
            if( i & 1){
                //odd
                oddMaxi = max(oddMaxi, i);
            }
            else if(i != 0){
                evenMini= min(evenMini, i);
            }
        } 
        return oddMaxi - evenMini;
    }
};